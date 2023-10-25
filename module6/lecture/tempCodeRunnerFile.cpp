#include <iostream>
using std::cout;
class Juice {
public:
int *price; 
void mem_request_for_price() {
price = new (std::nothrow) int;
if (!price) { cout << "Fail to request memory allocation \n";}
}
//Constructor
Juice (int price_val = 0){
cout << "Default Constructor \n";
mem_request_for_price();
*price = price_val;
}
/* Copy Constructor (for new obj)*/
Juice (const Juice &oldJuice){
cout << "Copy Constructor \n";
mem_request_for_price(); 
*price = *(oldJuice.price);
}
/* Assignment Operator (for existing obj)*/
// Return by reference to avoid creating another object
Juice &operator = (const Juice &oldJuice){
cout << "Assignment Operator \n";
*price = *(oldJuice.price);
return *this; //to allow multiple "=" operators used together
}
//Destructor
~Juice () {
//cout << "Destructor \n";
delete price;
}
};
int main() {
/* Note: whenever you have initiliazation of value: 
it will call constructor */
Juice juice1; //default contructor
Juice juice2(100); //default Constructor
Juice juice3 = juice2; //copy constructor 
Juice juice4(juice2); //copy constructor 
juice1 = juice2; /* Assignment Operator */
return 0;
}
