#include <iostream>
#include <vector>
using namespace std;

class Book {
    private:
        string *name; // name attribute is now pointer (*)
        int price;

    public:
    // initialize constructor. Should declare default argument in constructor
    Book(string name_val = " ", int price_val = 0) {
        this ->name = new string(name_val); // allocate in heap of constructor
        this -> price = price_val;
    };

    // Copy constructor
    Book (const Book &book) {
        cout << "Copy constructor is created" << "\n";
        name = new string;
        *name = *(book.name);
        price = book.price;
    }

    //Copy assignment operator
    Book &operator = (const Book &book) {
        cout << "Copy assignment operator is created" << "\n";
        name = new string;
        *name = *(book.name);
        price = book.price;
        return *this;
    }

    // delete name attribute after object is destroyed in order to avoid memory leaks (ro ri bo nho)
    // when object is out of scope (create in another function) it is automatically delete in memory allocation
    ~Book() {
        delete name;
    }

    // getter method
    string get_name() {
        return *name;
    };

    int get_price() {
        return price;
    };

    // setter method
    void set_name(string name_val) {
        *(this ->name) = name_val;
    };

    void set_price(int price_val) {
        this ->price = price_val;
    };
    
    string showInfo() {
        return "Name: " + *name + ", " + "Price: " + to_string(price) + "\n"; 
    }

};

int main() {
    Book book1;
    Book book2;

    //Copy assignment operator
    book1 = book2;
    
    // //Copy constructor
    Book book3 = book2;
}
