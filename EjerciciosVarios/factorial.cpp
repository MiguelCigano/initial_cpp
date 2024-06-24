#include <iostream>
using namespace std;

//prototype
int factorial(int n);

//main function
int main() {
    int n;
    cout << "Number: ";
    cin >> n;
    int fact = factorial(n);
    cout << "Factorial of " << n << " is " << fact << endl;
    return 0;
}

//function
int factorial(int n) {
    int fact = 1;
    for(int i=1; i<=n; i++) {
        fact = fact * i;
    }
    return fact;
}