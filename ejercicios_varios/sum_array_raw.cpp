#include <iostream>
#include <cstdint>
#include <array>
#include <string>

constexpr std::uint16_t MIN_VAL_WIN = 5;
constexpr std::uint16_t T = 9;
static float NEW_MIN_VALUES_WIN = 0.0;

void print_array_values(char *my_array, const std::uint16_t len) {
    for (std::uint16_t i = 0;  i < len; i++) {
        std::cout << my_array[i] << " "; 
    }
    std::cout<<std::endl;
}

std::uint16_t count_lost_turn(char *my_array, const std::uint16_t len) {
    std::uint16_t count = 0;
    for (std::uint16_t i = 0; i < len; i++) {
        if (my_array[i] == 'X') {
            std::cout << "Pos " << i  << std::endl;
            count++;
        }
    }
    return count;
}

std::uint16_t count_my_turn(char *my_array, const std::uint16_t len) {
    std::cout << std::endl;
    std::cout << "My turn"<< std::endl;
    std::uint16_t count = 0;
    for (std::uint16_t i = 0; i < len; i++) {
        if (my_array[i] == 'O') {
            std::cout << "Pos " << i  << std::endl;
            count++;
        }
    }
    return count;
}

int main(int argc, char **argv)  {
    
    
    char my_array[] = {'X', 'O', 'X', 'X', 'O', 'O', 'X', 'O', 'O'};
    // char my_array[] = {'X'};
    // char my_array[] = {'X', 'O'};
    const std::uint16_t len = sizeof(my_array) / sizeof(my_array[0]); 
    print_array_values(my_array, len);
    std::uint16_t count_lost = count_lost_turn(my_array, len);
    std::uint16_t my_count = count_my_turn(my_array, len);
    
    if (T == len) {
        if (count_lost >= MIN_VAL_WIN) {
            std::cout << "LOST GAME!" << std::endl;
            return 0;
        }
        else if (my_count >= MIN_VAL_WIN){
            std::cout << "WIN GAME!" << std::endl;
            return 0;
        }
        else {
            if (count_lost == my_count) {
                std::cout << "DRAW!" << std::endl;
                return 0;
            }
        }
    }
    else {
        if (T != len) {
            NEW_MIN_VALUES_WIN = (len / 2) + 1;
            std::cout << NEW_MIN_VALUES_WIN << std::endl;

            if (count_lost >= NEW_MIN_VALUES_WIN) {
                std::cout << "LOST GAME 2!" << std::endl;
                return 0;
            }
            else if (my_count >= NEW_MIN_VALUES_WIN){
                std::cout << "WIN GAME 2!" << std::endl;
                return 0;
            }
            else {
                if (count_lost == my_count) {
                    std::cout << "DRAW 2!" << std::endl;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}