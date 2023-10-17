#include <iostream>
#include <fstream>
#include <string>
#include <limits>  // for numeric_limits


using namespace std;

void savePassword() {
    string password;
    cin.ignore();;
    cout <<"Enter the password: ";
    // Clear the input buffer
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, password);

    ofstream writeFile("pwd.dat");
    if (writeFile.is_open()) {
        writeFile << password;
        writeFile.close();
        cout << "Save to the file!" << "\n";
    } else {
        cout << "File error!" << "\n";
    }
}

void readPassFromFile() {
    string password;
    ifstream readFile("pwd.dat");

    if (readFile.is_open()) {
        getline(readFile, password);
        readFile.close();
        cout << "Your password in pwd.dat: " << password << "\n";
    } else {
        cout <<"Can not read password in pwd.dat" << "\n";
    }
}

int main() {
    int choice;
    cout <<"Password management program" << "\n";
    cout <<"1. Save your password" << "\n";
    cout <<"2. Read your password " << "\n";
    cout <<"Your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        savePassword();
        break;
    case 2:
        readPassFromFile();
        break;
    default:
        cerr << "Invalid choice";
    }
    return 0;
}