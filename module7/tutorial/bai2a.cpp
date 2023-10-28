#include <iostream>
#include <vector>
using namespace std;

class Department;

class Staff {
    private:
        string name;
        string departmentName;
    public:
        Staff(string name = "", string departmentName = "")
        : name(name), departmentName(departmentName) {};

        void joinDept(Department &department);
        void leaveDept(Department &department);

        void showInfo() {
            cout << "Staff name: " << name << "\n";
            cout << "Department name: " << departmentName << "\n"; 
        };

        void setName(string name) {
            this ->name = name;
        };

        string getName() {
            return name;
        };

        // void setDepartment(string departmentName) {
        //     this -> deparmentName = deparmentName;
        // };

        // string getDepartmentName() {
        //     return deparmentName;
        // };

};

class Department {
    protected:
        string name;
        string location;
        vector <Staff*> staffList;
    
    public:
        Department(string name= "", string location = "", vector<Staff*> staffList = {})
        : name(name), location(location) , staffList(staffList){};

        void showInfo() {
            cout << "Department name: "<< name << "\n";
            cout << "Location: " << location << "\n";

            if (staffList.empty()) {
                cout << "None" << "\n";
            } else {
                for (Staff* staff : staffList) {
                    cout << "Staff: " << staff->getName() << ", ";
                }
                cout << "\n";
            }
        };

    friend class Staff;
};

class AcademicDept : public Department {
    private:
        int numberOfCourses;
    
    public:
        AcademicDept(int numberOfCourses = 0,string name = "", string location = "", vector<Staff*> staffList = {})
        : numberOfCourses(numberOfCourses),Department(name,location,staffList){};

        void showInfo() {
            Department::showInfo();
            cout << "Number of courses: " << numberOfCourses << "\n";
        }
};

class NonAcademicDept : public Department {
    private:
        int numberOfServices;
    
    public:
        NonAcademicDept(int numberOfServices = 0,string name = "", string location = "", vector<Staff*> staffList = {})
        : numberOfServices(numberOfServices), Department(name, location, staffList){};

        void showInfo() {
            Department::showInfo();
            cout << "Number of services: " << numberOfServices << "\n";
        };
};

void Staff::joinDept(Department &department) {
    if (departmentName != "") {
        leaveDept(department);
    };
    departmentName = department.name;
    department.staffList.push_back(this);
};

void Staff::leaveDept(Department &department) {
    for (int i = 0; i < department.staffList.size(); i++) {
        if (department.staffList[i] == this) { // this which is current Staff 
            department.staffList.erase(department.staffList.begin() + i);
            departmentName = "";
        }
    }
};

int main()
{
    Staff st1("Ling Huo Chong", ""), st2("Michael John", ""), st3("Ali Baba", ""); 

    AcademicDept dept1(20, "SSET", "Building 2, 4th floor", vector<Staff*>{});
    NonAcademicDept dept2(30, "ITS", "Building 1, Gnd floor", vector<Staff *>{});

    st1.joinDept(dept1);
    st2.joinDept(dept1);
    st3.joinDept(dept2);
    
    st1.showInfo();
    st2.showInfo();
    st3.showInfo();

    dept1.showInfo();
    dept2.showInfo();

    //movement of staff
    st1.leaveDept(dept1);
    st1.joinDept(dept2);

    cout << "After movement of staff\n";
    st1.showInfo();
    st2.showInfo();
    st3.showInfo();

    dept1.showInfo();
    dept2.showInfo();

    return 0;
}




