/* Pointer as data members */


#include <iostream>

class simpleCat
{
    public:
        simpleCat();
        ~simpleCat();
        int getAge() const { return *itsAge; }
        void setAge(int age) { *itsAge = age; }

        int getWeight() const { return *itsAge; }
        void setweight(int age) { *itsAge; }
}