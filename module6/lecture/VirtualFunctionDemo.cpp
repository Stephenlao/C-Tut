#include<iostream>
using namespace std;

// Base class
class Shape {
public:
    // Virtual function
    void draw() {
        cout << "Drawing a shape" << endl;
    }
};

// Derived class 1
class Circle : public Shape {
public:
    // Override the virtual function
    void draw() {
        cout << "Drawing a circle" << endl;
    }
};

// Derived class 2
class Square : public Shape {
public:
    // Override the virtual function
    void draw() {
        cout << "Drawing a square" << endl;
    }
};

int main() {
    Shape* shape;           // Base class pointer
    Circle circleObj;       // Derived class object
    Square squareObj;       // Another derived class object

    // Point to circle object and call draw()
    shape = &circleObj;
    shape->draw();          // Outputs: Drawing a circle

    // Point to square object and call draw()
    shape = &squareObj;
    shape->draw();          // Outputs: Drawing a square

    cout << "---------------------------------------------------" << "\n";

    // Circle circle1;
    // Square square1;

    // circle1.draw();
    // square1.draw();

    return 0;
}
