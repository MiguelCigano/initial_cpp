#include <iostream>
#include <cmath> // para uso de abs()

int fn(int x, int y) {
    int result = abs(x) + abs(y);
    return result;
}

int main() {
    int x = 5;
    int y = -9;
    int result;

    result = fn(x, y);
    std::cout << result << std::endl;
}