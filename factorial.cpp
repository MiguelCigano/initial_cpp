#include <iostream>

// unsigned long long fact(int var, unsigned long long &result){
void fact(int var, unsigned long long &result){
    for (int i = 2; i <= var; i++) {
        result *= i;
    }
}

int main(int argc, char **argv){
    int x = 4;
    unsigned long long result = 1;
    fact(x, result);
    std::cout << "result: " << result << std::endl;
    
    return 0;
}