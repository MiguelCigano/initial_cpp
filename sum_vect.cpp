#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};  
            }
        }
    }
    return {};  // Nunca llegará aquí, ya que siempre hay una solución garantizada
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);

    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}
