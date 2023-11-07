
// Template function
#if 0
#include <iostream>
using std::cout;
//Function template (one generic version)
template <typename inputType>
inputType add(inputType num1, inputType num2) {
return (num1 + num2);
}

int main(){
//Call function with int data type
    int result1;
    result1 = add<int>(2, 3);
    cout << result1 << "\n";
    //Call function with double data type
    double result2;
    result2 = add<double>(2.2, 3.3);
    cout << result2 << "\n";
    return 0;
}
#endif

// Multiple Generic Data Types & Type Check
#if 0
#include <iostream>
using std::cout;
using std::is_same;
//Function template (one generic version)
template <typename type1, typename type2>
double add(type1 num1, type2 num2) {
//Type Check
if (is_same<type1, int>::value) {
cout << "num1 is of int type \n";
} else {
cout << "num1 is of another data type \n";
}
return num1 + num2;
}
int main(){
//Call function with different data types
cout << add<int, int>(2, 3) << "\n";
cout << add<int, double>(2, 3.2) << "\n";
cout << add<double, int>(2.5, 3) << "\n";
return 0;
}


#endif



// Non type argument
#if 0
#include <iostream>
using std::cout;

/*  In this example, DISC_PERCENT is non-type argument
    Note: non-type arguments for a template must be a constant, usually an integer 
    (floating point values are not allowed)
*/
template <typename type, int DISC_PERCENT> 
type discountedValue(type amount){
    return amount - amount*DISC_PERCENT/100;
}


int main(){
    cout << discountedValue<int, 10>(1000) << "\n";
    cout << discountedValue<float, 20>(1000.0) << "\n";

    return 0;
}
#endif






#if 0
#include <iostream>
using std::cout;
// Class Template
template <typename type>
class Number {
private:
type num;
public:
//Constructors
Number(){}
Number(type num) : num(num) {}
type getNum() {
return num;
}
};
int main() {
// create object with int type
Number<int> intNum(7);
cout << "int Number = " << intNum.getNum() << "\n";
// create object with double type
Number<double> doubNum(7.7);
cout << "double Number = " << doubNum.getNum() << "\n";
return 0;
}
#endif





// Defining a Member Function Outside the Class Template
# if 0
#include <iostream>
using std::cout;
// Class Template
template <typename type>
class Number {
private:
type num;
public:
//Constructors
Number(){}
Number(type num) : num(num) {}
//function prototype
type getNum();
};
template <typename type>
type Number<type>::getNum() {
return num;
}
int main() {
// create object with int type
Number<int> intNum(7);
cout << "int Number = " << intNum.getNum() << "\n";
// create object with double type
Number<double> doubNum(7.7);
cout << "double Number = " << doubNum.getNum() << "\n";
return 0;
}
#endif



#include <iostream>
using std::cout;
//Function template (one generic version)
template <typename type>
type myFunct(type num1, type num2) {
return (num1 + num2);
}

template <>
char myFunct(char num1, char num2) {
return (num1 - num2);
}
int main(){
//Call function with int data type
cout << myFunct<int>(60.5, 2) << "\n";
//Call function with char data type
cout << myFunct<char>(60, 2) << "\n";
return 0;
}