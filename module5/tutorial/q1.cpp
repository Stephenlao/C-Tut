#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;


class Book {
    private:
        string name;
        int price;

    public:
        Book(string name_val = "", int price_val = 0)
        : name(name_val), price(price_val) {};


        string getName() {
            return name;
        }

        int getPrice() {
            return price;
        }


        string showInfo() {
            return "name: " + name + "price: " + std::to_string(price);
        }

};


int main() {
    //q1a
    Book* book1 = new (std::nothrow) Book("Book1", 250000);
    Book* book2 = new (std::nothrow) Book("Book2", 999999);
    Book* book3 = new (std::nothrow) Book("Book3", 600000);

    for (Book* book : {book1, book2, book3}) {
        cout << book->showInfo() << "\n";
        delete book;
    }

    if (book1 == nullptr || book2 == nullptr || book3 == nullptr) {
        std::cerr << "Fail to memory allocation!" << "\n";
        return -1;
    }

    // q1b
    int size;
    cout << "Enter the size of the book array: ";
    cin >> size;

    Book* bookArr = new Book[size];

    for (int i = 0; i < size; i++) {
        string name;
        int price;
        cout << "Enter " << i+1 << "'s book name: ";
        std::getline(cin >> std::ws, name);
        cout << "Enter " << i+1 << "'s book price: ";
        cin >> price;
        bookArr[i] = Book(name,price); 
    }

    int most_expensive_book = bookArr[0].getPrice();
    int index_most_expensive_book = 0;

    for (int i = 0; i < size; i++) {
        if (most_expensive_book < bookArr[i].getPrice()) {
            most_expensive_book = bookArr[i].getPrice();
            index_most_expensive_book = i;
        }
    }

    cout << "Most expensive book: " << bookArr[index_most_expensive_book].showInfo() << "\n";
    delete[] bookArr;
    return 0;
}