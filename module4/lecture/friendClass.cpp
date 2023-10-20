#include <iostream>
using namespace std;

class ClassA {
    private:
        int numA = 10;
    
    public:
        friend class ClassB;
};

class ClassB {
    private:
        int numB = 20;
    
    public:
    int add(ClassA obj_a) {
        return obj_a.numA + this ->numB;
    }
};

int main() {
    ClassB objB;
    ClassA objA;

    cout << "Sum: " << objB.add(objA);
    return 0;
}