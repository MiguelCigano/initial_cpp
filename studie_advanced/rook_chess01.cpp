#include <iostream>
#include <limits>
#include <algorithm>
#include <cstdint>
#include <string>
#include <fstream>
#include <map>

// Focus only in compute on square boards using maps.

bool is_board_valid(const std::vector<std::string>& board) {
    std::map<int, int> rrow_map;
    std::map<int, int> rcol_map;
    for (size_t i = 0; i < board.size(); ++i){
        for (size_t j = 0; j < board[i].length(); ++j) {
            if (board[i][j] == 'O') {
                rrow_map[i]++;
                rcol_map[j]++;
            }
        }
    }

    size_t i = 0;
    while (true) {
        if (i < board.size()) {
            if (!((rrow_map[i] <= 1) && (rcol_map[i] <= 1))) {
                return false;
            }
        }
        else {
            break;
        }
        i++;
    }
    return true;
}

int main(int argc, char** argv) {
    std::ifstream file("input1.txt");
    if (!(file.is_open())) {
        // std::cout << "test.." << std::endl;
        return -1;
    }

    std::string size;
    file >> size;
    file.ignore();

    std::vector<std::string> board;
    std::string line;
    while (getline(file, line)) {
        if (!(line.empty())) {
            board.push_back(line);
        }
    }

    file.close();

    std::cout << (is_board_valid(board) ? "yes!" : "no") << std::endl;

    return 0;
}

