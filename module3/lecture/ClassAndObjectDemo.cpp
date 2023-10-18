#include <iostream>
using namespace std;

//EXAMPLE OF FUNCTION OUTSIDE CLASS

// class Car {
//     public:
//         int speed = 100;
//         int add_speed(int num);
// };

// int Car::add_speed(int num) {
//     speed += num;
//     return speed;
// }

// int main() {
//     Car my_car;
//     cout << "my_car's default speed: " << my_car.speed << "\n";
//     cout << "my_car's new speed: " << my_car.add_speed(200);
//     return 0;
// }


// EXAMPLE OF CREATING CONSTRUCTOR

// class Car {
//     public:
//         int speed = 100;
//         int price = 1000;

//         Car() {
//             cout <<"Default constructor is called \n";
//         }
//         Car(int speed_val, int price_val) {
//             speed = speed_val;
//             price = price_val;
//         }
// };

// int main() {
//     Car car1;
//     Car car2(350,1500);
//     cout << "Car1 speed and price: " << " " <<car1.speed << " " << car1.price;
//     cout << "Car2 speed and price: " << " " <<car2.speed << " " << car2.price;
//     return 0;
// }


// EXAMPLE OF CREATING DEFAUTL ARGUMENTS

// class Car { // The class
//     public: // Access specifier
//         int speed; // Attribute
//         int price;
// //Default constructor with default arguments
//     Car(int speed_val = 100, int price_val = 1000) { 
//         cout << "Default constructor is called \n";
//         speed = speed_val;
//         price = price_val;
// }

//     void showInfo(){ 
//         cout <<"speed & price: " <<speed <<" " <<price <<"\n";
//     }
// };

// int main() {
// // Create Car objects (will call the constructors)
//     Car car1;
//     Car car2(500);
//     Car car3(500, 5000);
// // Print values
//     cout << "Car1: "; car1.showInfo();
//     cout << "Car2: "; car2.showInfo();
//     cout << "Car3: "; car3.showInfo(); 
//     return 0;
// }

// EXAMPLE OF ENCAPSULATION 

// #define DEFAULT_VAL 100
// #define PASSWORD_KEY 12345
// class myclass {
//     private: // Private attribute (cannot be accessed directly)
//         int num = DEFAULT_VAL; 

//     public: // Public functions (to manage access)
//         int get_num(){ return num; }; // getter function

//         void set_num(int new_val) { // setter function
//             int pwd;
//             std::cout << "Enter password: "; 
//             std::cin >> pwd;
//             if (pwd == PASSWORD_KEY) {
//                 num = new_val;
//                 std::cout << "Set new value successfully ! \n";
//             } else {
//                 std::cout << "Incorrect password ! \n";
//             }
//         }
// };

// int main() {
//     myclass object1;
//     std::cout << "Current num value: " << object1.get_num() << "\n";
//     object1.set_num(200);
//     std::cout << "New num value: "
//     << object1.get_num();
//     return 0;
// }


//EXAMPLE OF ARRAY OF OBJECTS
class Car { 
    public: 
        std::string brand; 
        int speed, price;
    Car (std::string brand_info, int speed_val, int price_val) {
        brand = brand_info; 
        speed = speed_val; 
        price = price_val;
}
};

int main() {
    Car MyCars[3] = { Car("Audi", 500, 10000), 
                      Car("BMW", 400, 8000), 
                      Car("Ferrari", 800, 20000) };
    for (int i = 0; i < 3; i++) {
        std::cout << "Car" << i << "'s brand, speed & price: "
        << MyCars[i].brand << " "
        << MyCars[i].speed << " "
        << MyCars[i].price << "\n";
}
    return 0;
}



