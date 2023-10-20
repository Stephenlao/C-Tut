#include <iostream>
using namespace std;

class BankAcc {
    public:
        std::string name = "";
        int amount = 0;

    BankAcc(std::string name_val = "", int amount_val = 0) 
    : name(name_val), amount(amount_val){};

    std::string toString() {
        return "Name = " + name + ", Amount = "
        + std::to_string(amount);
    };

    // Overload ++ when used as prefix (++ object)
    BankAcc operator ++ () {
        amount++; return *this;
    }
    // Overload ++ when used as postfix (object ++)
    BankAcc operator ++ (int) {
        amount++; return *this;
    }
};

int main() {
    BankAcc acc1("TCB", 1000), acc2("ACB", 2000);
    BankAcc result;
    // Use the overloaded operator ++ as prefix
    result = ++acc1;
    std::cout << result.toString() << "\n";
    // Use the overloaded operator ++ as suffix
    result = acc2++;
    std::cout << result.toString() << "\n";;
    return 0;
}
