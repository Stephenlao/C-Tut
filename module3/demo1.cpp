#include <iostream>
using namespace std;

int main() {
    int size;;
    cout << "How many number you want to enter: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i]; 
    }

    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    cout << "Max number: " << max;

    return 0;

}