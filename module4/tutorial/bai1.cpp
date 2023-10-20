#include <iostream>
#include <math.h>
using namespace std;

class ComplNum {
    private:
        double real, imag;

    // constructor declare in public
    public:
        ComplNum() {
            this->real = 0;
            this->imag = 0;
        }

        ComplNum(double real, double imag) {
            this->real = real;
            this->imag = imag;
        }

        // object - object
        ComplNum operator - (ComplNum comp1) {
            ComplNum temp;
            temp.real = this->real - comp1.real;
            temp.imag = this->imag - comp1.imag;
            return temp;
        };

        // object - double
        ComplNum operator - (double num) {
            ComplNum temp1;
            temp1.real = this->real - num;
            temp1.imag = this->imag;
            return temp1;
        };


        // object-- postfix
        ComplNum operator -- (int) {
            real--;
            imag--;
            return *this;
        }

        // --object prefix
        ComplNum operator -- () {
            real--;
            imag --;
            return *this;
        }
        
        //double - object
        // takes the object - num like this:   ComplNum operator - (double num).
        // this function indicates the object in class - num.
        // Thus, using FRIEND FUNCTION to accept NUM - OBJECT USING OVERLOADING FUNCTION OPERATOR

        friend ComplNum operator - (double num, ComplNum cn);

        friend double absolute(ComplNum cn);

        string toString() {
            if (imag >= 0) {
                return  to_string(real) + "+i " + to_string(imag) + "\n";
            } else {
                return  to_string(real) + "-i " + to_string(-imag) + "\n";
            }
        }    
};

ComplNum operator - (double num, ComplNum cn) {
    ComplNum temp2;
    temp2.real = num - cn.real;
    temp2.imag = num - cn.imag;
    return temp2;
};

double absolute(ComplNum cn) {
    return sqrt((cn.real * cn.real) + (cn.imag * cn.imag));
}

int main() {
    ComplNum cn1(3.0,4.0), cn2(1.0,2.0);
    ComplNum result;

    // OBJECT - OBJECT
    result = cn1 - cn2;
    cout << "Result of cn1 - cn2: " << result.toString() << "\n";

    // DOUBLE - OBJECT
    result = 2.0 - cn1;
    cout << "Result of 2.0 - cn1: " << result.toString() << "\n";

    // OBJECT - NUM
    result = cn1 - 2.0;
    cout << "Result of cn1 - 2.0: " << result.toString() << "\n";

    // POSTFIX OVERLOADING OPERATOR
    result = cn1--;
    cout << "Result of cn1--: " << result.toString() << "\n";

    // PREFIX OVERLOADING OPERATOR
    result = --cn1;
    cout << "Result of --cn1: " << result.toString() << "\n";


    // Calculate absolute
    cout << "Absolute of cn1: " << absolute(cn1) << "\n";





}