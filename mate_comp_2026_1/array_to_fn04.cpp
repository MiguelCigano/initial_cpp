#include <iostream>

int fn_count_element_array(int *a, const int n) {
    int count_num = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 2) {
            count_num++;
            std::cout << "Yes is two :)" << std::endl;
        }
        else {
            std::cout << "Not is two :(" << std::endl;
        }
    }
    return count_num;
}

int main() {
    const int n = 7;
    int a[n] = {0, 1, 2, 2, 1, 1, 1};
    int b[5] = {0, 0, 0, 0, 2};
    int c[] = {1, 1, 2, 1, 2, 2, 2}; // note that use []

    int result_a = fn_count_element_array(a, n);
    int result_b = fn_count_element_array(b, 5);
    int result_c = fn_count_element_array(c, 7);

    std::cout << "\nResult of a: " << result_a << std::endl;
    std::cout << "\nResult of b: " << result_b << std::endl;
    std::cout << "\nResult of c: " << result_c << std::endl;

    return 0;
}