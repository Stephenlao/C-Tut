#include <iostream>
using namespace std;
// EXAMPLE OF FUNCTION OVERLOADING AND THIS KEYWORD
// THIS KEYWORD ASSIGNS VALUE TO CURRENT ATTRIBUTES
class BankAcc{
    public:
        string name = "";
        int amount = 0;
/* Function overloading: 2 versions for the constructor */
BankAcc(string name = "", int amount = 0) { //v1
    this->name = name;
    this->amount = amount;
    }

BankAcc(int amount = 0) { //v2
    this->amount = amount;
} 

void showInfo() {
    std::cout << "Name = " << name
    << ", Amount = " << amount << "\n";
}
};

int main(){
    BankAcc myacc1("Techcombank",50000); //v1
    myacc1.showInfo();
    BankAcc myacc2(1000000); //v2
    myacc2.showInfo();
}