#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string user_input_char;
    cout <<"Enter string: ";
    getline(cin, user_input_char);

    for (char &c : user_input_char) {
        if (isupper(c)) {
            c = tolower(c);
        } else if (islower(c)) {
            c = toupper(c);
        }
    }

    cout << "New string after converting: " << user_input_char;
    return 0;
}
