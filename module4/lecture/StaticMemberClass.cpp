#include <iostream>
using namespace std;

class Car {
    public:
        string name;
        int price;

        static int objCount;
        static int getObjCount() {
            return objCount;
        }

        Car (string name, int price) {
            this ->name = name;
            this ->price = price;
            objCount++;
        }
};

// Initialize static attribute
// because this is the static attribute it belongs to entire class
// declare as below
int Car::objCount = 0;

int main() {
    cout << "Number of car objects: " << Car::getObjCount() << "\n";

    Car car1("Porsche Macan S 2023", 150000), car2("Mercedes GLC300 AMG 2023", 120000);
    cout << "Number of car objects: " << Car::getObjCount() << "\n";
    return 0;
}