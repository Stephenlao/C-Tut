#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <limits>

using std::cout;
using std::cin;
using std::cerr;
using std::fstream;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
    string line;
    fstream myFile;
    vector <string> vct;

    if (argc == 2) {
        // argv run based on C style => import cstring lib
        if (strcmp(argv[1], "-w") == 0) {
            int size;
            string name;
            int price;

            cout << "Enter total number of items: ";
            cin >> size;

            myFile.open("sellingItems.dat", std::ios::out);

            if (!myFile.is_open()) {
                cerr << "File path is not exist!" << "\n";
                return -1;
            }

            for (int i = 0; i < size; i++) {
                cout << "Enter name of item: ";
                // getline style for string input
                std::getline(cin >> std::ws, name);
                cout << "> price: ";
                cin >> price;
                myFile << name << " : " << price << "\n";
            }
            myFile.close();
        } else if (strcmp(argv[1], "-r") == 0) {
            myFile.open("sellingItems.dat", std::ios::in);
            if (!myFile.is_open()) {
                cerr << "No file path exists!" << "\n";
                return -2;
            } else {
                while(getline(myFile,line)) {
                    cout << line << "\n";
                }
            }
            myFile.close();
        } else if((strcmp(argv[1], "-s") == 0)) {
            int smallest_price = std::numeric_limits<int>::max();
            myFile.open("sellingItems.dat", std::ios::in);
            if (!myFile.is_open()) {
                cerr << "No file path exists!" << "\n";
                return -2;
            } else {
                while(getline(myFile,line)) {
                    // call isstringstream operates like cin, this library parse any type
                    // in this case it parses string (name) and double(price)
                    std::istringstream iss(line);
                    string name;
                    int price;

                    // readline until meet ':' then stop and add string value to name, similarly add int value to price
                    if (std::getline(iss, name, ':') && iss >> price) {
                        if (price < smallest_price) { // Compare price with smallest price
                            smallest_price = price;
                            vct.clear(); // clear line that added to vct
                            vct.push_back(line); // add line to vct which have smallest price
                        }
                    }
                }
                myFile.close();
                 // Print lines with the smallest price
                for (auto smallestLine :vct) { // auto type: accept all types
                    cout << smallestLine << "\n";
                    }
            }
            } else {
                cerr << "Incorrect inputted!" << "\n";
            }
        } 
    return 0;
}
