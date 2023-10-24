#include <iostream>
using std::cout;

// int main(){
//     int x = 5;
//     int &xRef = x;
//     // This line declares a reference named xRef that refers to the integer variable x. 
//     // A reference is, in essence, an alias for another variable. 
//     // After this statement, both x and xRef refer to the same memory location. 
//     // Any changes made through xRef will be reflected in x and vice-versa.
//     x = 10;
//     cout << "x = " << x 
//     << ", xRef = " << xRef << "\n";
//     xRef = 20;
//     cout << "x = " << x 
//     << ", xRef = " << xRef << "\n";
// return 0;
// }

int main() {
    int x = 10;
    int xref = x;  // xref is a separate integer that gets a copy of x's value
    cout << "x: " << x << "xref: " << xref<< "\n";
    xref = 20;  // this does NOT modify x, only xref
    cout << "x: " << x << "xref: " << xref; // will print 10

}