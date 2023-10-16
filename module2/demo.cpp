#include <iostream>
#include <fstream>
using std::cout;


    void func1 (int x) { //x is passed by value
        x = 10; 
        cout << "x in func1 = " << x << "\n"; //???
}
    void func2 (int *x) { //x is passed by pointer
        *x = 20; 
        cout << "x in func2 = " << *x << "\n";
}
    void func3 (int &x) { //x is passed by reference
        x = 30; 
        cout << "x in func3 = " << x << "\n"; //?
}


int main() {
    int val = 0; 
    cout << "val in main = " << val << "\n\n"; 
    func1(val); //pass by value: value of val is copied to x
    cout << "val after func1 call = " << val << "\n\n";

    func2(&val); //pass by pointer: address of val is copied to pointer x
    cout << "val after func2 call = " << val << "\n\n";

    func3(val); //pass by reference: x is reference of val (like an alias)
    cout << "val after func3 call = " << val << "\n\n"; //
    return 0;
}


