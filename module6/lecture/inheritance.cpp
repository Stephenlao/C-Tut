#include <iostream>
using namespace std;

// parent base class
class Animal {
    public:
    void eat() {
        cout << "I can eat!" << endl;
}
};

// child derived class
class Dog : public Animal {
    public:
    void bark() {
        cout << "I can bark! Woof woof!!" << endl;
}
};

int main() {
    Dog dog1;
    dog1.eat(); //dog1 has method from the parent class
    dog1.bark(); //dog1 has method from its own class
    return 0;
}
