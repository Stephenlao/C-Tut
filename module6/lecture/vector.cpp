#include <iostream>
#include <vector>
using std::cout;

int main() {
    std::vector<int> numVt {1, 2, 3, 4, 5};

    numVt.push_back(60); //add value 60 at the end

    numVt.push_back(70); //add value 70 at the end

    cout << "First element: " << numVt[0] << "\n";

    cout << "Last element: " << numVt[numVt.size() - 1] << "\n";

    numVt.pop_back(); //remove last element

    numVt.erase(numVt.begin() + 2); //remove element at index 2

    // //Print out all elements with ranged based for loop
    cout << "All elements after changes: ";
    for (int &num : numVt) {
        cout << num << " ";
    }
    return 0;
}