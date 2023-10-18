#include <iostream>
using namespace std;

class Cat {
    public:
        string name;
        int age;

    // declare member intialized list
    Cat(string name_val, int age_val) : name(name_val), age(age_val) {}

};

class Person {
    public:
        Cat cat;
        string name;

    // declare member intialized list
    Person(Cat cat_obj, string name_val) : cat(cat_obj), name(name_val) {}
};

int main() {
    Cat cat1("Muffy",3);
    Cat cat2("Tom", 6);
    Cat cat3("Tim", 2);

    Person person[3] = {
        Person(cat1, "KhangKobe"),
        Person(cat2, "KhanhLebron"),
        Person(cat3, "NghiaPorzingis")
    };

    // Access to age of cat of person[0]
    int cat_highest_age = person[0].cat.age;
    int person_has_cat_highest_age = 0;  // Initialized to 0
    for (int i = 0; i < 3; i++) {
        if (cat_highest_age < person[i].cat.age) {
            cat_highest_age = person[i].cat.age;
            person_has_cat_highest_age = i;
        }
    }

    cout << "Person information has cat whose age is highest: " << person[person_has_cat_highest_age].name << " ," <<
    "Cat information: " << person[person_has_cat_highest_age].cat.name << " " << person[person_has_cat_highest_age].cat.age << "\n";  
}
