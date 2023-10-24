#include <iostream>
using std::cout;
using std::string;


class Data {

private:
    string name;
    int* arr;
public:
    Data(std::string name) { // constructor
        cout << "Constructor of " << name << " is called \n";
        this->name = name;
    arr = new int[1000]; //dynamic memory allocation
}; 

    ~Data() { // destructor
        cout << "Destructor of " << name << " is called \n\n";
        delete[] arr; //remove this one will cause Memory Leak (computer hang)
}; 
};

//A function with local object to test
void myFunc(int i){
    std::string name = "data" + std::to_string(i);
    Data myData(name); //create a local object
}
int main() {
    //call the function many times
    for (int i = 0; i < 10; i++) {
        myFunc(i); 
    }
return 0;
}
