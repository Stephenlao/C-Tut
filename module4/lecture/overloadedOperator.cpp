#include <iostream>
using namespace std;


class BankAcc {
    public:
        string name = "";
        int amount = 0;

    // declare constructor as member initializer
        BankAcc (string name_val = "", int amount_val = 0)
        : name(name_val) , amount(amount_val) {}

        string toString() {
            return "Name = " + name + ", Amount = " +
            to_string(amount); // convert int to string
        }

    // overloaded operator add two objects together  
    BankAcc operator + (BankAcc acc2) {
        BankAcc temp;
        if (this->name == acc2.name) {
            temp.name = this->name;
            temp.amount = this->amount + acc2.amount;
            return temp;
        }
        cerr <<"Cannot add accounts: names are different \n";;
        return temp; 
    }
};

int main() {
    BankAcc acc1("TCB", 1000),
            acc2("TCB",3000),
            acc3("ACB",5000),
            result;
    
    // automatically call overloaded operator
    result = acc1 + acc2;
    cout << result.toString() << "\n\n";
    result = acc2 + acc3;
    cout << result.toString() << "\n\n";
    return 0;
}