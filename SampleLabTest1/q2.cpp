#include <iostream>
#include <string>
#include <limits>
using std::cin;
using std::cout;
using std::string;

class EWallet {
    private:
        string name;
        double balance;
    public:
        EWallet(string name_val = "", double balance_val = 0)
        : name(name_val), balance(balance_val) {};

    bool pay(double amount, string coupon) {
        if (balance > amount) {
            if (coupon == "BLACKFRIDAY") {
                double dis_amount = (amount * 30) /100;
                balance = balance - dis_amount;
                return true; 
            } else {
                balance = balance - amount;
                return true; 
            }
        } else {
            cout << "Your balance is not enough to pay!" << "\n";
            return false;
        }
    }

    string getName() {
        return name;
    }
    void setName(string name_val) {
        name = name_val;
    }

    double getBalance() {
        return balance;
    }

    void setBalance(double balance_val) {
        balance = balance_val;
    }
       // q2a defind friend function to add n to obj.balance 
    friend void operator>>(double n, EWallet& obj);
};



void operator>>(double n, EWallet& obj) {
        obj.balance += n; // Increase the balance of EWallet by n
    }




class User {
    private:
        string name;
        string pwd;
        EWallet acc;
    public:
    
        User(string name_val = "",string pwd_val = "",EWallet acc_val = EWallet())
        : name(name_val), pwd(pwd_val), acc(acc_val) {};

        bool verifyPass() {
            string pwd_input;
            cout << "Please enter password for verification: ";
            std::getline(cin >> std::ws, pwd_input);
            if(pwd_input == pwd) {
                // cout << "Password verify successfull!" << "\n";
                return true;
            } else {
                // cout << "Incorrect password!" << "\n";
                return false;
            }
        }

        bool doPayment() {
            double amount;
            string coupon;
            if (verifyPass()) {
                cout << "Password verification correct!" << "\n";
                cout << "Enter the amount of money for payment: ";
                cin >> amount;
                cout << "Enter coupon code: ";
                std::getline(cin >> std::ws, coupon);
                cout << "Your current balance: " << acc.getBalance() << "\n";
                acc.pay(amount,coupon);
                cout << "Balance after pay: " << acc.getBalance() << "\n\n";
                return true;
            } else {
                cout << "Incorrect password!" << "\n";
                return false;
            }
        };

        void displayBalance() {
            cout << "Balance: " << acc.getBalance() << "\n";
        }
        string getName() {
            return name;
        }

        EWallet getAcc() {
            return acc;
        }

        friend void operator>>(User &userA, User &userB);
};

void operator>>(User &userA, User &userB) {
    userB.acc.setBalance(userB.acc.getBalance() + userA.acc.getBalance()); // Add the balance of fromUser to toUser
    userA.acc.setBalance(0); // Set fromUser's balance to zero
}
    

int main() {
    // QUESTION 2A
    cout << "-------------Question 2a-------------" << "\n";
    EWallet ewallet1("Momo", 1000);

    double amounttoAdd = 200;
    // add 200 to ewallet1 balance
    amounttoAdd >> ewallet1;

    cout << "Balance wallet 1: " <<  ewallet1.getBalance() << "\n";
    ewallet1.pay(200,"BLACKFRIDAY");
    cout << "Balance after pay: " << ewallet1.getBalance() << "\n\n";



    EWallet ewallet2("ZaloPay", 500);
    cout << "Balance wallet 2: " <<  ewallet2.getBalance() << "\n";
    ewallet2.pay(200,"CYBERMONDAY");
    cout << "Balance after pay: " << ewallet2.getBalance() << "\n\n";



    EWallet ewallet3("Internet Banking", 900);
    cout << "Balance wallet 3: " <<  ewallet3.getBalance() << "\n";
    ewallet3.pay(700,"CYBERMONDAY");
    cout << "Balance after pay: " << ewallet3.getBalance() << "\n\n";


    EWallet ewallet4("Vi dien tu", 200);
    cout << "Balance wallet 4: " <<  ewallet4.getBalance() << "\n";
    ewallet4.pay(700,"CYBERMONDAY");
    cout << "Balance after pay: " << ewallet4.getBalance() << "\n\n";


    // QUESTION 2B
    cout << "-------------Question 2b-------------" << "\n";

    User user1("StephenLao","Khang is awesome", ewallet1),
    user2("Vivien Doan","Uyenstrawberry", ewallet2);
    user1.doPayment();


    cout << "Before transferring " << "\n";
    user1.displayBalance();
    user2.displayBalance();

    cout << "After transferring " << "\n";
    user1 >> user2;
    user1.displayBalance();
    user2.displayBalance();
    cout << "\n";

    //QUESTION 2C
    cout << "-------------Question 2c-------------" << "\n";
    User userArr[4] = {User("A","abc123",ewallet1),
                       User("B","bcd345",ewallet2), 
                       User("C","cdf456",ewallet3),
                       User("D","efg789",ewallet4)};



    double smallest = std::numeric_limits<double>::max();
    double secondSmallest = std::numeric_limits<double>::max();
    User* secondSmallestUser = nullptr;

    for (User& user : userArr) {
        double balance = user.getAcc().getBalance();

        if (balance < smallest) {
            secondSmallest = smallest;
            smallest = balance;
        } else if (balance < secondSmallest && balance != smallest) {
            secondSmallest = balance;
            secondSmallestUser = const_cast<User*>(&user); // Not ideal to use const_cast, but necessary in this context
        }
    }

    if (secondSmallestUser != nullptr) {
        std::cout << "Second smallest balance is " << secondSmallest
                  << " held by user " << secondSmallestUser->getName() << std::endl;
    } else {
        std::cout << "There is no second smallest balance." << std::endl;
    }

    return 0;
}