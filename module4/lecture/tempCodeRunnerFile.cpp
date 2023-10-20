#include <iostream>
using namespace std;
using std::string;

class BankAcc {
    public:
        string name = "";
        int amount = 0;

    // declare constructor as member initializer
        BankAcc (string name_val = "", int amount_val = 0)
        : name(name_val) , amount(amount_val) {}

        string toString() {
            return "Name = " + name + ", Amount = " +
            to_string(amount); // convert int to string
        }

    // overloaded operator add two objects together  
    BankAcc operator + (BankAcc acc2) {
        BankAcc temp;
        if (this->name == acc2.name) {
            temp.name = this->name;
            temp.amount = this->amount + acc2.amount;
            return temp;
        }
        cerr <<"Cannot add accounts: names are different \n";;
        return temp; 
    }
};

int main() {
    BankAcc acc1("TCB", 1000),
            acc2("TCB",3000),
            acc3("ACB",5000),
            result;
    
    // automatically call overloaded operator
    result = acc1 + acc2;
    cout << result.toString() << "\n\n";
    result = acc2 + acc3;
    cout << result.toString() << "\n\n";
    return 0;
}



// EXAMPLE OF FUNCTION OVERLOADING AND THIS KEYWORD
// THIS KEYWORD ASSIGNS VALUE TO CURRENT ATTRIBUTES
// class BankAcc{
//     public:
//         string name = "";
//         int amount = 0;
// /* Function overloading: 2 versions for the constructor */
// BankAcc(string name = "", int amount = 0) { //v1
//     this->name = name;
//     this->amount = amount;
//     }

// BankAcc(int amount = 0) { //v2
//     this->amount = amount;
// } 

// void showInfo() {
// std::cout << "Name = " << name
// << ", Amount = " << amount << "\n";
// }
// };

// int main(){
//     BankAcc myacc1("Techcombank",50000); //v1
//     myacc1.showInfo();
//     BankAcc myacc2(1000000); //v2
//     myacc2.showInfo();
//     return 0;
// }


// class BankAcc {
//     public:
//         std::string name = "";
//         int amount = 0;

//     BankAcc(std::string name_val = "", int amount_val = 0) 
//     : name(name_val), amount(amount_val){};

//     std::string toString() {
//         return "Name = " + name + ", Amount = "
//         + std::to_string(amount);
//     };

//     // Overload ++ when used as prefix (++ object)
//     BankAcc operator ++ () {
//         amount++; return *this;
//     }
//     // Overload ++ when used as postfix (object ++)
//     BankAcc operator ++ (int) {
//         amount++; return *this;
//     }
// };

// int main() {
//     BankAcc acc1("TCB", 1000), acc2("ACB", 2000);
//     BankAcc result;
//     // Use the overloaded operator ++ as prefix
//     result = ++acc1;
//     std::cout << result.toString() << "\n";
//     // Use the overloaded operator ++ as suffix
//     result = acc2++;
//     std::cout << result.toString() << "\n";;
//     return 0;
// }

// EXAMPLE OF FRIEND FUNCTION
// class Distance {
//     private:
//         int meter;
           
//         //Declare a non-member function is a Friend
//         // as friend function it allows to access all member variables(attributes, function,etc)
//         // to other outside methods. Thus in main we can access to meter without error
//         friend int addFive(Distance d);
    
//     public:
//         Distance() : meter(0){}; // truyen attribute value directly     
// };

// int addFive(Distance d) {
//     d.meter += 5;
//     return d.meter;
// };
// int main() {
//     Distance dist;
//     cout << "Distance: " << addFive(dist);
//     return 0;
// }

//EXAMPLE OF OVERLOADING OPERATOR AS A FRIEND FUNCTION 
// class Point2D {
//     private:
//         int x, y;
    
//     public:
//         Point2D(int xval = 0, int yval = 0)
//         : x(xval), y(yval){};
    
//         friend Point2D operator + (Point2D point, int num); // allow Point2D + int
//         friend Point2D operator + (int num, Point2D point); // allow int + Point2D

//         string toString() {
//             return "x= " + to_string(x) + ", y = " + to_string(y);
//         }
// };

// Point2D operator + (Point2D point, int num) {
//     Point2D temp;
//     temp.x = point.x + num;
//     temp.y = point.y + num;
//     return temp;
// };

// Point2D operator + (int num, Point2D point) {
//     return point + num;
// };

// int main() {
//     Point2D pointA(100,200), pointB;

//     pointB = 20 + pointA;
//     cout << "\nValue of pointB: " << pointB.toString() << "\n";

//     pointB = pointA + 30;
//     cout << "\nValue of pointB: " << pointB.toString() << "\n";
//     return 0;
// }