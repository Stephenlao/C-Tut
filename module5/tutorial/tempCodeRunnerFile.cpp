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
    // Cau 1a
    int size = 3;
    // create bookArr pointer (always create pointer when using dynamic memory allocation)
    // new Book[size] create size to store in bookArr
    Book *bookArr = new Book[size] {
        Book("Book1", 150000),
        Book("Book2", 220000),
        Book("Book3", 299000)
    };

    // check whether bookArr is null or not
    if (bookArr == nullptr) {
        cerr << "Memory allocation not successful!";
    } else {
        // using vector in order to manage size of memory allocation efficient and effectively
        // to avoid crashing memory or memory leak
        vector <Book> b;  
        for (int i = 0; i < size; i++) {
            b.push_back(bookArr[i]); // write each elements from bookArr to b
        };

        // Iterate through b and print in console
        for (Book i : b) {
            cout << i.showInfo();
        };
    }
    
    delete [] bookArr;
}