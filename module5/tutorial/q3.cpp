#include <iostream>
using std::cout;
using std::cin;



int main() {
    double a,b;

    cout << "Enter value of A and B for division: ";

    try {
        cin >> a >> b;
        if (b == 0) {
            throw -1;
        }
    } catch(int errorCode) {
        std::cerr << "b is 0 ! Error code:" << errorCode << "\n";

        do {
            cout << "Please enter the value for b again: ";
            cin >> b;
        } while (b == 0);
    }

    cout << "Result: a/b = " << (double) a/b << "\n";
    return 0;
}