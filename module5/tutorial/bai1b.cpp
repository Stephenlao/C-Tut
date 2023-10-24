#include <iostream>
#include <vector>
using namespace std;

class Book {
    private:
        string name;
        int price;

    public:
    // initialize constructor. Should declare default argument in constructor
    Book(string name_val = " ", int price_val = 0) {
        this ->name = name_val;
        this -> price = price_val;
    };

    // getter method
    string get_name() {
        return name;
    };

    int get_price() {
        return price;
    };

    // setter method
    void set_name(string name_val) {
        this ->name = name_val;
    };

    void set_price(int price_val) {
        this ->price = price_val;
    };
    
    string showInfo() {
        return "Name: " + name + ", " + "Price: " + to_string(price) + "\n"; 
    }

};

int main() {
    int size, price;
    string name;
    cout << "Enter number: ";
    cin >> size;

    Book *bookArr = new Book[size];

    Book bookArr1[] = 

    for (int i = 0; i < size; i++) {
        cout << "Enter name of "<< "book " << i+1 << ": ";
        cin >> name;

        cout << "Enter price of "<< "book " << i+1 << ": ";
        cin >> price;

        bookArr[i].set_name(name);
        bookArr[i].set_price(price);
    };

    int expensive_price = bookArr[0].get_price();
    Book expensive_book;
    for (int i = 0; i < size; i++) {
        if (expensive_price < bookArr[i].get_price()) {
            expensive_price = bookArr[i].get_price();
            expensive_book = bookArr[i];
        }
    }
    cout << "The most expensive book: " << expensive_book.showInfo();
    delete[] bookArr;
}
