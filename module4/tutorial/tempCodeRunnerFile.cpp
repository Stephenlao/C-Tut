#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string reverse(string str) {
    int len = str.length();
    int lastIdx = len - 1;

    for (int i = 0; i < len/2; i++) {
        char temp;
        temp = str[i];
        str[i] = str[lastIdx];
        str[lastIdx] = temp;

        lastIdx--;
    }
    return str;
};

string convert(string str) {
    for (int i = 0; i< str.length();i++) {
       if (isupper(str[i])) {
            str[i] = tolower(str[i]);
       } else {
            str[i] = toupper(str[i]);
       }
    }
    return str;
};

int main() {
    string string1, string2;
    cout <<"Enter string 1: ";
    getline(cin, string1);

    cout << "Enter string 2: ";
    getline(cin, string2);

    cout <<"Reverse string: " << reverse(string1) << "\n";
    cout <<"Converted string: " << convert(string2) << "\n";
    return 0;

} 