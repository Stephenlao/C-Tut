#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        int studentID;
    
    public:
        Student(string name_val = "", int studentID = 0) : name(name_val), studentID(studentID) {
            cout << "Constructor of Student class is created" << "\n";
        };

        ~Student() {
            cout << "Destructor of Student class" << "\n";
        };

        void setName(string name_val) {
            this -> name = name_val;
        };

        string getName() {
            return name;
        };

        void setStudentID(int studentID) {
            this ->studentID = studentID;
        };

        int getStudentID() {
            return studentID;
        };

        virtual string toString() {
            return "Name: " + name + " "+ "StudentID: " + to_string(studentID);
        };
};

class Staff {
    private:
        string name;
        int staffID;
    public:
        Staff(string name_val = "", int staffID = 0) : name(name_val), staffID(staffID) {
            cout << "Constructor of Student class is created" << "\n";
        };

        ~Staff() {
            cout << "Destructor of Staff class" << "\n";
        };

        void setName(string name_val) {
            this -> name = name_val;
        };

        string getName() {
            return name;
        };

        void setStaffID(int staffID) {
            this -> staffID = staffID;
        };

        int getStaffID() {
            return staffID;
        };

        virtual string toString() {
            return "Name: " + name + " " + "StaffID: " + to_string(staffID);
        };
};

class Tutor: public Staff, public Student {
    public:
        void consultation() {
            cout << "Doing consultation";
        };

        Tutor(string name_val, int tutorID) : Staff(name_val,tutorID) {
            cout << "Constructor of Tutor class is created" << "\n";
        };

        ~Tutor() {
            cout << "Destrutor of Tutor" << "\n";
        };

        void setName(string name_val) {
            Staff::setName(name_val);
        };

        string getName() {
            return Staff::getName();
        };

        void setStaffID(int staffID) {
            Staff::setStaffID(staffID);
        };

        int getStaffID() {
            return Staff::getStaffID();
        };
        
        string toString() {
            return Staff::toString(); 
        };
};

void showInfoStudent(Student &std) {
    cout << std.toString() << "\n";
}

void showInfoStaff(Staff &staff) {
    cout << staff.toString() << "\n";
}

int main() {
    Tutor t1("Lebron", 12345678);
    showInfoStaff(t1);
    showInfoStudent(t1);

    Student stud1("Khang",39787);
    showInfoStudent(stud1);

    Staff staff1("Kobe",5588);
    showInfoStaff(staff1);

    return 0;
}