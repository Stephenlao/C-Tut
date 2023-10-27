#include <iostream>
#include <vector>
using namespace std;

class Book {
    private:
        string title;
        int availableCopies;
        vector<string> nameOfBorrowers;
    
    public:
        // declare as member intializer
        Book(string title = "", int availableCopies = 0, vector<string> nameOfBorrowers ={})
        :title(title), availableCopies(availableCopies), nameOfBorrowers(nameOfBorrowers) {};

        void showInfo() {
            cout << "Book title: " << title << "\n";
            cout << "Available copies: " << availableCopies << "\n";

            for (string i : nameOfBorrowers) {
                cout << "Name of borrowers: " << i << "\n";
            }
        };

        // as friend 'User' class can access/call all attributes and functions from Book
        // regardless of private or protected access
        friend class User;
};

class User {
    private:
        string name;
        vector<Book*> borrowedBooks;
    
    public:
        User(string name = "", vector<Book*> borrowedBooks = {}) {
            this -> name = name;
            this -> borrowedBooks = borrowedBooks;
        };

        bool doBorrow(Book &abook) {
            if(abook.availableCopies == 0) {
                cout << "This book is out of stock" << "\n";
                return false;
            };

            // because borrowedBook is the vector pointer thus
            // we return &abook which is return address to borrwedBooks
            borrowedBooks.push_back(&abook);
            abook.nameOfBorrowers.push_back(this -> name);
            abook.availableCopies--;
            return true;
        };

        bool doReturn(Book &abook) {
            for (int i = 0; i < borrowedBooks.size(); i++) {
                // compare title in each borrowedBook vector array whether
                // equal to book title of borrowers. == 0 which is identical
                if (borrowedBooks[i]->title.compare(abook.title) == 0) { 
                    for (int j = 0; j < abook.nameOfBorrowers.size(); j++) {
                        if (abook.nameOfBorrowers[j].compare(this ->name) == 0) {
                            abook.nameOfBorrowers.erase(abook.nameOfBorrowers.begin() + j);
                            abook.availableCopies++;
                            borrowedBooks.erase(borrowedBooks.begin() + j);
                            return true;
                        };
                    }   cout << "You are not borrow " << abook.title << "this books in book lists" << "\n";
                        return false;
                };
                
            }   cout << "This book does not exists" << "\n";
                return false;
        };

        
        void showInfo(){
            cout << "Name: " << name << endl;
            cout << "Borrowed books: ";

            if(borrowedBooks.empty())
            {
                cout << "None.\n";
            }else{
                cout << "\n";

                for(Book* i : borrowedBooks){
                    cout << i->title << endl; 
                }
            }
            cout << endl;
        };
};

class superUser : public User {
    public:
         superUser(string name = "", vector<Book*> borrowedBooks = {}) 
         : User(name,borrowedBooks) {}; // declare constructors inherit from User

         bool doBorrow(Book &book1, Book &book2) { // & target to orginal object not create copy
            if (User::doBorrow(book1) && User::doBorrow(book2)) {
                return true;
            }
            return false;
         };
};

int main() {
        vector<Book*> books = {
        new Book("Book1", 3, vector<string>{} ), 
        new Book("Book2", 3, vector<string>{} ),
        new Book("Book3", 3, vector<string>{} )
    };
    
    User user1("Vinh Khang", vector<Book *>{}), user2("Uyen Doan", vector<Book *>{});

    cout << "Initial\n";

    books[0]->showInfo();
    books[1]->showInfo();
    books[2]->showInfo();
    user1.showInfo();
    user2.showInfo();

    cout << "\nSome borrowing\n";

    user1.doBorrow(*books[0]);
    user1.doBorrow(*books[1]);
    user2.doBorrow(*books[1]);
    user2.doBorrow(*books[2]);
    
    books[0]->showInfo();
    books[1]->showInfo();
    books[2]->showInfo();
    user1.showInfo();
    user2.showInfo();

    cout << "\nSome returning\n";

    user1.doReturn(*books[2]);
    user1.doReturn(*books[1]);
    user2.doReturn(*books[1]);

    books[0]->showInfo();
    books[1]->showInfo();
    books[2]->showInfo();
    user1.showInfo();
    user2.showInfo();

    cout << "SuperUser mode\n";

    superUser sUser1("Christano Ronaldo", vector<Book *>{});
    sUser1.showInfo();
    
    sUser1.doBorrow(*books[0], *books[1]); 
    
    books[0]->showInfo();
    books[1]->showInfo();
    books[2]->showInfo();
    
    sUser1.showInfo();
    
    //free memory allocated previously for books from line 141-145
    for(Book* i : books)
        delete i;   

    return 0;
}


