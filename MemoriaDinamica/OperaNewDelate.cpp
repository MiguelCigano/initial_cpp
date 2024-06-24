#include <iostream>

using namespace std;

int main()
{
    int *ptr;
    ptr = new int(10);

    int variable = *ptr;
    variable++;
    int &variable2 =*ptr;
    variable2++;

    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << variable << std::endl;
    std::cout << variable2 << std::endl;
    
    return 0;
}