// Call Contructors/Methods of the base class


#include <iostream>
#include <string>
#include <vector>

#if 0
class Department{
private:
    std::string name;
public:
    Department(std::string name = ""){
        this->name = name;
}

void showInfo(){
    std::cout << "Name of Department = " << name << "\n";
}
};

class AcadDept: public Department {
private:
    int numOfCourses;
public:
AcadDept(){}

AcadDept(std::string name, int numOfCourses)
    : Department(name) { //call constructor of base class
    this->numOfCourses = numOfCourses;
}

void showInfo() {
    Department::showInfo(); //call method of base class
    std::cout << "Num of Courses = " << numOfCourses << "\n";
}
};

int main(){
    AcadDept sset("SSET", 25);
    sset.showInfo();
    return 0;
}
#endif



//<--------------------------------------------------------------------------->
//<--------------------------------------------------------------------------->
// LINKED LIST



// 1. SINGLY LINKED LIST
#if 0
#include <iostream>
using std::string;
using std::cout;

class HouseHold{
public:
    string name;
    HouseHold *purchasedPerson = nullptr;

    //Constructor
    HouseHold (string name = "") : name(name) {}
};

int main(){
    /* Initialize nodes */
    HouseHold hh1("HouseHold 1"), hh2("HouseHold 2"), hh3("HouseHold 3");
    /* Save reference of first node in head (orginal HouseHold)*/
    HouseHold *origHouseHold = &hh1;
    /* Connect nodes */
    hh1.purchasedPerson = &hh2; //hh2 bought the house from hh1
    hh2.purchasedPerson = &hh3; //hh3 bought the house from hh2
    hh3.purchasedPerson = nullptr; //no person bought the house from hh3 yet
    /* Loop through the linked list */
    cout << "\nLinked list of the house transactions is: \n";
    HouseHold *temp = origHouseHold; //start with first node (head)
    while (temp != nullptr) {
    cout << temp->name << " --> ";
    temp = temp->purchasedPerson; //access next node
}
}
#endif


// 2. Doubly linked list
#if 1
#include <iostream>
using std::string;
using std::cout;
using std::cin;

class HouseHold{
    public:
        string name;
        HouseHold *purchasedPerson = nullptr;
        HouseHold *soldPerson = nullptr;

        // Constructor
        HouseHold(string name = "") : name(name) {}
};

int main() {
    // Intitialize nodes (create three objects)
    HouseHold hh1("HouseHold 1"), hh2("HouseHold 2"), hh3("HouseHold 3");

    // Connect nodes (record transactions)
    HouseHold *origHouseHold = &hh1; // head (first household) 

    // hh1 sell to house to hh2 hh1 --> hh2
    hh1.purchasedPerson = &hh2;
    hh2.soldPerson = &hh1;

    // hh2 sell to house to hh3 hh2 --> hh3
    hh2.purchasedPerson = &hh3;
    hh3.soldPerson = &hh2;

    HouseHold *lastHouseHold = &hh3; // tail (last household)

    // Loop through the linked list
    // Go forward from head to tail
    printf("\nLinked HouseHolds (next buyers) are: \n");
    HouseHold *temp = origHouseHold;
    while (temp != nullptr) {
        cout << temp->name << "---->";
        temp = temp->purchasedPerson; // access next node
    }

    printf("\n\nLinked Households (previous owners) are: \n");
    temp = lastHouseHold;
    while (temp != nullptr) {
        cout << temp->name << "---->";
        temp = temp->soldPerson; // access next node
    }
}
#endif