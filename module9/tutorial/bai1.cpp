#include <iostream>
using std::cout;
using std::cin;

// Function template to swap two values of the same type
template <typename T>
void swap(T& num1, T& num2) { // Using & in order to passed num1 and num2 by reference to swap so that the original variables in main are actually swapped.
    T temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "Number 1 after swap: " << num1 << "\n";
    cout << "Number 2 after swap: " << num2 << "\n";
}

int main() {
    int num1, num2;
    cout << "Enter number 1: ";
    cin >> num1;
    cout << "Enter number 2: ";
    cin >> num2;
    swap(num1, num2); // No need to specify <int,int> as template arguments are deduced.
}
