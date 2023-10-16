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
    cin >> hex >> hexval;

    cout <<"Output: " << dec << showbase << hexval;
    cout << hex << showbase << " " << hexval << "\n";
    return 0;
}