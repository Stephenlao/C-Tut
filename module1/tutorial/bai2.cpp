#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int arr[size];
    int max = arr[0];
    float temp_avg = 0;

    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i< size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
        
        temp_avg += arr[i];
    }

        
    cout << "Max number: " << max << "\n";
    cout << "Average: " << temp_avg/size;
    
    return 0;
}