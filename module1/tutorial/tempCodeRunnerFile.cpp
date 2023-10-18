#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter number to reverse: ";
    cin >> number;

    int reverse = 0;
    while ((number) !=0) {
        reverse = (reverse * 10) + (number % 10); // Build the reversed number
        number /= 10;
    }

    cout << "Number after reversed: " << reverse;
    return 0;
}