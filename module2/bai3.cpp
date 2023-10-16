#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
    // a
    // int size = 50;
    // char user_char[size];
    // cout << "Enter characters: ";
    // // cin.getline get all characters in line
    // cin.getline(user_char, size);


    // for (int i = 0; i < strlen(user_char); i++) {
    //     cout << user_char[i] << " ";
    // }
    // return 0;

    //b
    // cout << setw(9) << setfill('0') << 1.234;

    //c
    // setprecision: (maximum number of digits to be written
    // fixed: fix value in floating point
    // cout << fixed << setprecision(2) << 1.234;

    //d
    // Input: 0x10
    // Output: 16 0x16

    int hexval;
    cout <<"Enter hexadecimal number to convert into decimal and hexadecimal form in ('0x') format (ex: 0x10):  ";
    // accept value enter from user then convert it to hexa and store in hexval
    cin >> hex >> hexval;

    // The output begins with "Output: ". Then, std::dec sets the output to decimal format, 
    //and std::showbase makes sure that the base (like 0x for hexadecimal) is shown in subsequent outputs. 
    //The decimal value of the inputted hexadecimal number is then displayed. 
    cout <<"Output: " << dec << showbase << hexval;

    //std::hex switches the output format to hexadecimal. The value in hexValue is then printed in hexadecimal format. 
    //The std::showbase is still in effect, 
    //so the output will have the 0x prefix to indicate that the number is in hexadecimal.
    cout << hex << showbase << " " << hexval << "\n";
    return 0;
}