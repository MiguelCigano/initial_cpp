#include <iostream>
#include <bitset>

int main() {
    int arr[7]= {0, 0, 0, 0, 0, 0, 0};
    arr[1] &= ~(1);
    std::bitset<16>;

    for (int i = 0; i <= 7; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}