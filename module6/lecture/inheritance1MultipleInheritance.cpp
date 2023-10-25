#include <iostream>
using std::string;
using std::cout;

// Base class (grandfather)
class Animal {
    public:
        int age; // attribute
        Animal(int ageVal = 0) : age(ageVal) { 
        cout << "ANIMAL constructor \n";
}
};

// Derived class (father)
class Cat: public Animal {
    public:
        string featherColor;

    Cat(int ageVal = 0, string colorVal = "") 
    : Animal(ageVal), featherColor(colorVal) { 
    cout << "CAT constructor\n";
    }
};

// Another base class (mother)
class Pet {
    public:
        string name;
        Pet(string nameVal = "") : name(nameVal) { 
        cout << "PET constructor\n";
}
};

// Derived class (child)
class Kitten: public Pet, public Cat{ // inherit from Pet and Cat
    public:
        Kitten(string name = "", string color = "", int age = 0) 
        : Pet(name), Cat(age, color) { 
        cout << "KITTEN constructor\n";
}
};

int main() {
    //Create objects through contructor
    Kitten kitten1("Hello Kitty", "white", 10);
    //Access all inherited members (attributes/ methods)
    cout << "Age = " << kitten1.age << "\n";
    cout << "Color = " << kitten1.featherColor << "\n";
    cout << "name = " << kitten1.name << "\n";
    return 0;
}
