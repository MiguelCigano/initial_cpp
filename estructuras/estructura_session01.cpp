#include <iostream>

struct Person {
    std::string name;
    int age;
    float height;
};

void modified_height(Person *p, float new_height) {
    // float new_height2 = 1.90;
    (*p).height = new_height;
    // p->height = new_height2;
}

void modified_age(Person &p) {
    p.age++;
    p.age++;
    std::cout << "Age in fn: " << p.age << std::endl;
}

void print_person(Person p) {
    std::cout << p.name << ", " << p.age << std::endl;
}

int main(int argc, char *argv[]) 
{
    Person person2 = {"Vanessa", 30, 1.64};
    print_person(person2); // Pasa una copia de la persona
    modified_age(person2);
    modified_height(&person2, 1.80);
    std::cout << "Height in main: " << person2.height << std::endl;

    return 0;
}