#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

template <typename T>
T min3(const T& arg1, const T& arg2, const T& arg3) { // using const because make it no change and apply to function
    T args_arr[] = {arg1, arg2, arg3};
    T min_val = args_arr[0];
    for (int i = 1; i < 3; i++) { // Just iterate over the 3 elements
        if (min_val > args_arr[i]) {
            min_val = args_arr[i]; // Missing semicolon added
        }
    }
    return min_val;
}

template <typename T>
void userInput() {
    T args1, args2, args3;
    cout << "Enter the 1st argument: ";
    cin >> args1;
    cout << "Enter the 2nd argument: ";
    cin >> args2;
    cout << "Enter the 3rd argument: ";
    cin >> args3;
    T min_value = min3(args1,args2,args3);
    cout << "The min of " << args1 << ", " << args2 << ", " << args3 << " is " << min_value << "\n";
    };
// }

int main() {
    userInput<int>();
    userInput<double>();
    userInput<string>();
    return 0;
}
