#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter number to reverse: ";
    cin >> number;

// example why reverse = (reverse * 10) + (number % 10):

// Say we start with num = 456 and reversed = 0.

// First Iteration:

// num % 10 = 6
// reversed * 10 = 0 (since reversed is initially 0)
// New reversed = 0 + 6 = 6
// Second Iteration (after num becomes 45):

// num % 10 = 5
// reversed * 10 = 60
// New reversed = 60 + 5 = 65
// Third Iteration (after num becomes 4):

// num % 10 = 4
// reversed * 10 = 650
// New reversed = 650 + 4 = 654
// At the end of this process, for the input num of 456, the reversed value becomes 654

    int reverse = 0;
    while ((number) !=0) {
        reverse = (reverse * 10) + (number % 10); // Build the reversed number
        number /= 10;
    }

    cout << "Number after reversed: " << reverse;
    return 0;
}


