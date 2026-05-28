#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
    public:
        std::vector<std::vector<int>> generate(int rows) {
            std::vector<std::vector<int>> trian;
            trian.reserve(rows); // capacity is not size

            for (size_t i = 0; i < rows; ++i) {
                std::vector<int> row(i + 1, 1); // (size, value)
                for (size_t j = 1; j < i; ++j) {
                    row[j] = trian[i - 1][j] + trian[i - 1][j - 1];
                }
                trian.push_back(row);
            }

            return trian;
        }

        void print_trian(const std::vector<std::vector<int>>& trian) {
            for (const auto& row : trian) {
                for (const auto& num : row) {
                    std::cout << num << ", " << std::endl;
                }
                std::cout << std::endl;
            }
        }
};

int main(int argc, char** argv) {
    Solution sol = Solution();
    int rows = 5;
    std::vector<std::vector<int>> result = sol.generate(rows);
    sol.print_trian(result);

    return 0;
}