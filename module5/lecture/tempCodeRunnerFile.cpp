#include <iostream>
using std::cout; using std::string;

class Acc{
public:
    int amount;
    Acc(int amountVal = 0) : amount(amountVal){} //Constructor
    void showInfo(){cout << "amount = " << amount << "\n"; }
    //note: declare friend for external funct if attribute is private
};

/* Operator overloading: int n >> obj : increase amount of obj by n */
//PASS & RETURN BY VALUE: DOES NOT WORK
#if 0 //change to #if 1 to select pass and return by value
    Acc operator >> (int n, Acc obj){
    cout << "Pass by Value. mem addr of obj param = " << &obj << "\n"; 
    obj.amount = obj.amount + n;
    return obj;
}
#else
//PASS & RETURN BY REFERENCE: CORRECT !
    Acc &operator >> (int n, Acc &obj){
    cout << "Pass by Reference. mem addr of obj param = " << &obj << "\n"; 
    obj.amount = obj.amount + n;
    return obj;
}
#endif

int main() {
    Acc acc1(1000);
    cout << "mem addr of acc1 arg = " << &acc1 << "\n";
    //require pass by reference
    500 >> acc1; //should have 1500 in acc1
    acc1.showInfo();
    //require pass and return by reference
    200 >> (500 >> acc1); //should have 2200 in acc1
    acc1.showInfo();
    return 0;
}