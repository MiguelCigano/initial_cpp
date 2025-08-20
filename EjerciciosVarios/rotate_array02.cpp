#include <iostream>
#include <vector>

class Solution {
    public:
        void rotate(std::vector<int>& nums, int k) {
            int n = nums.size();
            std::vector<int> temp_nums(n);
            auto it = 0;
            size_t las_index_t = temp_nums.size() - 1;

            for (auto i = nums.size() - 1; i >= nums.size() - k; i--) {
                temp_nums[it] = nums[i];
                it++;
            }
            std::cout << std::endl;

            for (auto i = k; i < nums.size(); i++) {
                temp_nums[i] = nums[i];
            }
            std::cout << std::endl;

            for (int i = 0; i < temp_nums.size(); i++) {
                std::cout << temp_nums[i];
            }
            std::cout << std::endl;
            
        }

        void print(std::vector<int>& nums) {
            for (int i = 0; i < nums.size(); i++) {
                std::cout << nums[i];
            }
            std::cout << std::endl;
        }
};


int main() {

    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution sol;
    constexpr int k = 3;
    sol.print(nums);
    sol.rotate(nums, k);
    // sol.print(nums);
    return 0;
}