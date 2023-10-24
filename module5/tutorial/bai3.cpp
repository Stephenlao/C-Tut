#include <iostream>
using namespace std;

int main() {
    int a, b, result;
    cout << "Enter number a for division: ";
    cin >> a;
    cout << "Enter number b for division: ";
    cin >> b;

    while (b == 0) {
        try
        {
            if (b == 0) {
                throw 101; // 101 this will immediately transfer control to the catch block that handles this type of exception.
            }
        }
        catch(int errorCode1)
        {
            cerr << "b should greater than 0! Error code: " << errorCode1 << "\n";
            cout <<"Enter number b: ";
            cin >> b;
        }
    };
    result = a/b;

    cout << "The result is: " << result << "\n";
}