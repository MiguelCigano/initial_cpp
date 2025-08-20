#include <iostream>
#include <vector>

std::vector<int> two_sum(std::vector<int> &nums_vec, int target) {
    int n = nums_vec.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums_vec[i] + nums_vec[j] == target) {
                return {i, j};  
            }
        }
    }
    return {};  // Nunca llegará aquí, ya que siempre hay una solución garantizada
}

int main() {
    std::vector<int> nums_vector = {3, 4, 2, 0, 7, 11, 15};
    int target = 9;
    std::vector<int> result = two_sum(nums_vector, target);

    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}
