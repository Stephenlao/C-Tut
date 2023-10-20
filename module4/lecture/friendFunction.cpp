#include <iostream>
using namespace std;
// EXAMPLE OF FRIEND FUNCTION
class Distance {
    private:
        int meter;
           
        //Declare a non-member function is a Friend
        // as friend function it allows to access all member variables(attributes, function,etc)
        // to other outside methods. Thus in main we can access to meter without error
        friend int addFive(Distance d);
    
    public:
        Distance() : meter(0){}; // truyen attribute value directly     
};

int addFive(Distance d) {
    d.meter += 5;
    return d.meter;
};
int main() {
    Distance dist;
    cout << "Distance: " << addFive(dist);
    return 0;
}
