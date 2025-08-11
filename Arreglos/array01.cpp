#include <array>
#include <cstdint>
#include <iostream>

// C++-Style using arrays and Template
// Double definition
template <std::size_t N>
void print_array_values_cpp(const std::array<std::uint32_t, N>& my_array2) {
    for (std::uint32_t i = 0; i < my_array2.size(); i++) {
        std::cout << my_array2[i] << std::endl;
    }
}

int main(int argc, char** argv) {
    constexpr auto len = 5U;

    std::array<std::uint32_t, len> my_array2 = {};
    print_array_values_cpp(my_array2);

    auto my_array3 = std::array<std::uint32_t, 4U>{1, 2, 3, 4};
    print_array_values_cpp(my_array3);

    return 0;
}