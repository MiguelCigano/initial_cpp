#include <iostream>
#include <map>
#include <vector>
#include <limits>
#include <algorithm>
#include <fstream>

// Focus only in compute on square boards using vectors.

bool checking_vectors(const std::vector<int>& rv, const std::vector<int>& cv) {
    // O(N + M)
    for (size_t i = 0; i < rv.size(); ++i) {
        if (rv[i] > 1) {
            return false;
        }
    }

    for (size_t j = 0; j < cv.size(); ++j) {
        if (cv[j] > 1) {
            return false;
        }
    }
    return true;
}

bool is_board_valid(const std::vector<std::string>& board) {
    if (board.empty()) {
        return true;
    }

    size_t max_cols = 0;
    for (const std::string &row : board) {
        max_cols = std::max(max_cols, row.length());
    }

    std::vector<int> rrow_vec(board.size(), 0);
    std::vector<int> rcol_vec(max_cols, 0);

    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].length(); ++j) {
            if (board[i][j] == 'O') {
                rrow_vec[i]++;
                rcol_vec[j]++;
            }
        }
    }
    
    return checking_vectors(rrow_vec, rcol_vec);
}

int main(int argc, char **argv) {
    std::ifstream file("input1.txt");
    if (!file.is_open()) {
        std::cerr << "Error during open file!" << std::endl;
        return -1;
    }

    std::vector<std::string> v_results;
    constexpr int BOARD_SIZE = 4;
    int T = 0;
    if (!(file >> T)) {
        return -1;
    }

    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (size_t b = 0; b < T; ++b) {
        std::vector<std::string> single_board;
        std::string line;

        while (single_board.size() < BOARD_SIZE && std::getline(file, line)) {
            if (!(line.empty())) {
                single_board.push_back(line);
            }
        }

        if (is_board_valid(single_board)) {
            v_results.push_back("yes");
        }
        else {
            v_results.push_back("no");
        }
    }

    file.close();

    for (const std::string& s : v_results) {
        std::cout << s << std::endl;
    }
    
    return 0;
}