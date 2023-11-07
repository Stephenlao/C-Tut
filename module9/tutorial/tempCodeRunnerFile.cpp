#include <iostream>
using std::cout;
using std::cin;


template<int N>
class factorial {
    public:
        int value;

        factorial() {
            int result = 1;
            for (int i = 1; i <= N; i++) {
                result = result * i;
            }
            value = result;
        }
};

template<>
class factorial<0> {
    public:
        int value = 1;

        factorial(){}
};

int main() {
    factorial<0> factorial1;
    cout << "Factorial of 0 is: " << factorial1.value << "\n";

    factorial<4> factorial2;
    cout << "Factorial of 4 is: " << factorial2.value << "\n";
}