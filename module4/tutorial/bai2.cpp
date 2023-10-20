#include <iostream>
#include <fstream>
using namespace std;

class BankAcc {
    public:
        string name;
        float amount;

        BankAcc() {
            name = "";
            amount = 0;
        }

        BankAcc (string name_val, float amount_val) {
            this->name = name_val;
            this->amount = amount_val;
        }

        // return string therefore all info must be string
        string toString() {
            return "Bank info: " + name + ", " + to_string(amount) + "\n";
        }

        void withdraw(float num) {
            if (amount >= num) {
                amount -= num;
            } else {
                cerr << "Current amount is exceed num, can not withdraw!" << "\n\n";
            }
        };
};

// if using command line argument always declare argc and argv
int main(int argc, char* argv[]) {
    int size = 3;

    BankAcc bankacc[size] = {BankAcc("Sacombank", 1000000),
                          BankAcc("Techcombank", 1500000),
                          BankAcc("Agribank", 500000)
                         };
                     
    
    for (int i = 0; i < size; i++) {
        cout << bankacc[i].toString() << "\n";
    };

    for (int i = 0; i < size; i++) {
        double money;
        cout << "Enter withdraw to substract from balance bank acc " << i + 1 << ": ";
        cin >> money;
        bankacc[i].withdraw(money);
    };

    cout << "Balance after withdraw: " << "\n";
    cout << bankacc[0].toString();
    cout << bankacc[1].toString();
    cout << bankacc[2].toString();

// The condition if (argc == 2) is used to check if the program has received exactly one command-line argument (other than the program name itself). 
// If it has, then it assumes this argument to be the filename where the bank account details should be saved. 
// If this argument isn't provided (i.e., if argc isn't 2), 
// then the program won't attempt to save the data to a file.

    if (argc == 2) {
        ofstream writeFile;
        // not argv[0] it always the program name
        // argv[1] is extract the file name that's why argc (argument count) should = 2 to ensure there is 2 args declare
        writeFile.open(argv[1]); 
        if (!(writeFile.is_open())) {
            cerr << "Error in opening file!";
            return -1;
        } else {
            for (int i = 0; i < size ; i++) {
                writeFile << "Bank info: " << bankacc[i].name << ", " << bankacc[i].amount << "\n";
            };
            cout <<"Saved successfully in" << " " << argv[1] << "\n";
        }
        writeFile.close();
    }
    return 0;
    }

 
