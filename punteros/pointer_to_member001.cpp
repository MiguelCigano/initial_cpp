#include <iostream>
#include <ostream>

class Base {
    public:
        Base(int i) : x_(i) {}
        virtual ~Base() {}
        virtual void func() { std::cout << "Base::func()" << std::endl; }
    private:
        int x_;
};

class Derived : public Base {
    public:
        Derived(int i) : Base(i) {}
        virtual void func() { std::cout << "Derived::func()" << std::endl; }
};


int main(int argc, char **argv) 
{
    Base *b = new Derived(42);
    void (Base::*fp)() = &Base::func;
    (b->*fp)();
}