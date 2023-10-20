#include <iostream>
using namespace std;

//EXAMPLE OF OVERLOADING OPERATOR AS A FRIEND FUNCTION 
class Point2D {
    private:
        int x, y;
    
    public:
        Point2D(int xval = 0, int yval = 0)
        : x(xval), y(yval){};
    
        friend Point2D operator + (Point2D point, int num) ; // allow Point2D + int
        friend Point2D operator + (int num, Point2D point); // allow int + Point2D

        string toString() {
            return "x= " + to_string(x) + ", y = " + to_string(y);
        }
};

Point2D operator + (Point2D point, int num) {
    Point2D temp;
    temp.x = point.x + num;
    temp.y = point.y + num;
    return temp;
};

Point2D operator + (int num, Point2D point) {
    return point + num;
};

int main() {
    Point2D pointA(100,200), pointB;

    pointB = 20 + pointA;
    cout << "\nValue of pointB" << pointB.toString() << "\n";

    pointB = pointA + 30;
    cout << "\nValue of pointB" << pointB.toString() << "\n";
    return 0;
}