#include <iostream>

int main() {
    int n = 4;
    int a[n] = {1, 35, 2, 4};
    int greater = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] > greater) {
            greater = a[i];
        }
    }
    std::cout << greater << std::endl;
}