#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;

template <typename T>
class TestVector {
    private:
        vector<T> vectorAttrs;
    public:
        TestVector(vector<T> vectorAttrs)
        : vectorAttrs(vectorAttrs) {};

        void findVectorElement() {
            T number;
            cout << "Enter number you want to find in vector: ";
            cin >> number;
            int numberIndex = 0; // Initialize with -1 to indicate "not found"
            for (int i = 0; i < vectorAttrs.size(); i++) {
                if (number == vectorAttrs[i]) {
                    numberIndex = i;
                    break; // Stop the loop if we find the number
                }
            }
            if (numberIndex != -1) {
                cout << "Index of " << number << " is " << numberIndex << "\n"; 
            } else {
                cout << number << " not found in the vector.\n";
            }
        }

        void insertVectorElement() {
            T number;
            int index;
            cout << "Enter number you want to insert into vector: ";
            cin >> number;
            cout << "Enter index you want your chosen number to be positioned in: ";
            cin >> index;
            while (index < 0 || index > static_cast<int>(vectorAttrs.size())) {
                if (index < 0) {
                    cout << "Index could not be less than 0. Please re-enter again: ";
                } else if (index > static_cast<int>(vectorAttrs.size())) {
                    cout << "Index could not be greater than " << vectorAttrs.size() << ". Please re-enter again: ";
                }
                cin >> index;
            }
            vectorAttrs.insert(vectorAttrs.begin() + index, number);
            cout << "Insert successfully!\n";
        }

        void removeVectorElement() {
            T number;
            cout << "Enter number you want to remove: ";
            cin >> number;
            int removeIndex = 0;
            for (int i = 0; i < vectorAttrs.size(); i++) {
                if (number == vectorAttrs[i]) {
                    removeIndex = i;
                } 
            }
            vectorAttrs.erase(vectorAttrs.begin() + removeIndex);
            cout << "Remove successfully!\n";
        }

        vector<T>& getVectorArr() {
            return vectorAttrs;
        }
};

int main() {
    // TEST INT DATA TYPE CASE 
    # if 0
    vector<int> vectorInt = {8, 5, 6, 22, 50, 31};
    cout << "Number in vector: ";
    for (int num : vectorInt) {
        cout << num << ", ";
    }
    cout << "\n";
    TestVector<int> vectorIntObj(vectorInt);
    vectorIntObj.findVectorElement();
    vectorIntObj.insertVectorElement();
    vectorIntObj.removeVectorElement();
    cout << "Updated vector: ";
    for (int num : vectorIntObj.getVectorArr()) {
        cout << num << ", ";
    }
    cout << "\n";
    #endif

    // TEST DOUBLE DATA TYPE CASE 

    #if 1
    vector<double> vectorInt = {8.5, 5, 6.5, 22.3, 50.1, 31.4};
    cout << "Number in vector: ";
    for (double num : vectorInt) {
        cout << num << ", ";
    }
    cout << "\n";
    TestVector<double> vectorIntObj(vectorInt);
    vectorIntObj.findVectorElement();
    vectorIntObj.insertVectorElement();
    vectorIntObj.removeVectorElement();
    cout << "Updated vector: ";
    for (double num : vectorIntObj.getVectorArr()) {
        cout << num << ", ";
    }
    cout << "\n";
    #endif
    return 0;
}
