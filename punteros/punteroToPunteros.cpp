#include <iostream>

using namespace std;

int main(void)
{
    int num = 10;
    int *ptr;
    ptr = &num;

    // se define un puntero (ptr2) a un int que apunta a otro puntero (ptr) a un int
    int **ptr2 = &ptr;
    
    cout << num << endl;
    cout << &num << endl; 
    cout << ptr << endl;
    cout << &ptr << endl,
    cout << *ptr << endl;
    cout << ptr2 << endl;
    cout << "//////////////////////" <<endl;

    int num1 = 11;
    int num2 = 22;
    int num3 = 33;

    // se define un arreglo de punteros
    int **arrNum = new int*[3];
    
    arrNum[0] = &num1;
    arrNum[1] = &num2;
    arrNum[2] = &num3;

    cout << "////////////////////// A: " <<endl;
    cout << arrNum << endl,
    cout << arrNum + 1 << endl;
    cout << arrNum + 2 << endl;

    cout << "////////////////////// B: " <<endl;
    cout << *(arrNum) << endl,
    cout << *(arrNum + 1) << endl;
    cout << *(arrNum + 2) << endl;
    
    cout << "////////////////////// C:" <<endl;
    cout << **(arrNum) << endl,
    cout << **(arrNum + 1) << endl;
    cout << **(arrNum + 2) << endl;

    return 1;
}