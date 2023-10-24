#include <iostream>

int main() {
try { // all code you want to handle possible exceptions
//request memory allocation (very large size will throw bad_alloc exception)
    int *ip = new int[10000];
    int age;
    std::cout << "Enter age: "; std::cin >> age;
    if (age <= 16) {
        throw 101; //throw a custom error code (here is an integer value)
    }
}
catch (std::bad_alloc& ba) { //Handles std::bad_alloc exception
    std::cerr << "bad_alloc exception caught: " << ba.what() << '\n';
}
catch (int errorCode) { // Handles custom exception
    std::cerr << "Access denied (16+). Error Code: " << errorCode;
}
catch (...) { // Handles all other generic exeptions
    std::cerr << "Generic Exceptions !\n";
}
return 0;
}