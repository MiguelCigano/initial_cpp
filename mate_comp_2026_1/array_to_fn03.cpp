#include <iostream>

void fn_modifier_array(int *a, const int n) {
    const int gain = 2;
    for (int i = 0; i < n; ++i) {
        a[i] *= gain;
    }
}

int main() {
    const int n = 3;
    int a[n] = {1, 3, 9};
    
    // Pass the array "a" and the size "n" 
    fn_modifier_array(a, n);

    return 0;
}