#include <iostream>
using namespace std;


int minimum_arr_func(int num) {
    int arr[num];
    for (int i = 0; i < num; i++) {
        cout <<"Enter number" << i+1 << ": ";
        cin >> arr[i];
    }

    int min_val = arr[0];
    for (int i = 0; i < num; i++) {
        if (min_val > arr[i]) {
            min_val = arr[i];
        }
    }
    return min_val;
}

int main() {
    int user_input;
    cout << "How many numbers you want to enter: ";
    cin >> user_input;

    int main_min_val = minimum_arr_func(user_input);
    cout << "Minimum value in an array: " << main_min_val;
    return 0; 
}