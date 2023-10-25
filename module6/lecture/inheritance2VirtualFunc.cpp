#include <iostream>
using std::cout;

class Animal { // parent base class
public:
/* IMPORTANT: remove virtual keyword will not
call the child class' eat() version in activity() function
*/
void eat() { 
    cout << "I can eat! \n";
}
};

class Dog : public Animal { // child derived class
    public:
    void eat() {
        cout << "The dog eat in his own way \n";
}

    void bark() {
        cout << "I can bark! Woof woof!! \n";
}
};

//A function that takes a pointer/reference of Animal class
// void animalEat(Animal &anm) { 
//     anm.eat(); 
// }

int main() {
    Dog dog1;
    dog1.eat();
    // animalEat(dog1);

    Animal animal1;
    animal1.eat();
    // animalEat(animal1);
}