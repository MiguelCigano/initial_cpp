#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
    public:
        std::vector<std::vector<int>> generate(int rows) {
            std::vector<std::vector<int>> trian;
            
            for (size_t i = 0; i < rows; ++i) {
                if (i == 0) {
                    std::vector<int> indx_zero = {1};
                    trian.push_back(indx_zero);
                }
                else if (i == 1) {
                    std::vector<int> indx_one = {1, 1};
                    trian.push_back(indx_one);
                }
                else {
                    std::vector<int> vec_nums;
                    for (size_t indx_num = 0; indx_num <= i; ++indx_num) {
                        int num = 0;
                        if (indx_num == 0) {
                            // begin
                            num = 1;
                        }
                        else if (indx_num == i) {
                            // end
                            num = 1;
                        }
                        else {
                            num = trian[i - 1][indx_num - 1] + trian[i - 1][indx_num];
                        }
                        vec_nums.push_back(num);
                    }
                    trian.push_back(vec_nums);
                }
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