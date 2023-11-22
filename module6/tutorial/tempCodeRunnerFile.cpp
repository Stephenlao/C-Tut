#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::vector;
using std::fstream;

class Student {
    private:
        string name;
        int studentID;
    public:
        Student(string name_val = " ", int studentID_val = 0)
        : name(name_val), studentID(studentID_val) {};
    

        string getName() {
            return name;
        }

        void setName(string name_val) {
            name = name_val;
        }

        int getStudentID() {
            return studentID;
        };

        void setStudentID(int studentID_val) {
            studentID = studentID_val;
        };

        string toString() {
            return "Name: " + name + ", StudentID: " + std::to_string(studentID);
        }
};



class SchoolSystem {
private:
        vector<Student> studentVct;
public:
        SchoolSystem() {};

        void addStudent() {
            string name;
            int studentId;
            cout << "Enter student name: ";
            std::getline(cin >> std::ws, name);
            cout << "Enter student ID: ";
            cin >> studentId;
            // create student object after ask user input
            Student student_obj(name,studentId);
            // add student object to student vector list
            studentVct.push_back(student_obj);
            cout << "Add student successfull!" << "\n\n";

            // Create myFile for adding student object into student.dat
            fstream myFile;
            myFile.open("student.dat", std::ios::app); // append mode in order to add each student obj to student.dat
            if (!myFile.is_open()) {
                cerr << "File path is not exist!" << "\n";
                return;
            }
            myFile << student_obj.toString() << "\n";
            myFile.close();
            cout << "Add student to file successfull!" << "\n";           
        };
    

    void removeStudent() {
    int studentID;
    cout << "Enter student ID that you would like to remove: ";
    cin >> studentID;
    bool foundInVector = false;

    // Find and remove student from vector
    // for (int i = 0; i < studentVct.size(); i++) {
    //     if (studentVct[i].getStudentID() == studentID) {
    //         studentVct.erase(studentVct.begin() + i);
    //         cout << "Erase student successfully from vector!" << "\n";
    //     }
    // else {
    //     cout << "No student with ID " << studentID << " found in the vector." << "\n";
    //     return;
    // } 
    // }


    // Read and update the file
    vector<string> lines;
    string line;
    bool studentFound = false; // variable to track if studentID is found

    fstream myFile("student.dat", std::ios::in);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            if (line.find("StudentID: " + std::to_string(studentID)) != string::npos) {
                studentFound = true; // studentID found in the line
                continue; // skip adding this line to lines vector
            }
            lines.push_back(line);
        }
        myFile.close();

        if (!studentFound) {
            cerr << "Student ID not found." << "\n";
            return; // Exit the function if studentID is not found
        }

        // Write updated data back to the file
        myFile.open("student.dat", std::ios::out | std::ios::trunc);
        for (const auto& l : lines) {
            myFile << l << "\n";
        }
        myFile.close();
        cout << "Erased student successfully from file!" << "\n";
    } else {
        cerr << "Unable to open file." << "\n";
    }
    };



        // Read student.dat and print out in console
        void viewStudents() {

            string line;
            fstream myFile("student.dat", std::ios::in);

            // check whether data has in file
            if (myFile.peek() == std::ifstream::traits_type::eof()) { 
                cout << "There is no data within student.dat!\n";
                myFile.close();
                return;  // Exit the function
        }

            if (myFile.is_open()) {
                // read each line in student.dat
                while (getline(myFile, line)) { 
                    // print out student information in console
                        cout << "Student Information: " << line << "\n";
                    }
                myFile.close();
            } else {
                cerr << "Unable to open file." << "\n";
                myFile.close();
            }
        };

        vector<Student> getStudentVector() {
            return studentVct;
        }
};

int main() {
    SchoolSystem schoolSystem;
    int choice;

    do {
        cout << "School Management System " << "\n";
        cout << "1. View all students" << "\n";
        cout << "2. Add students" << "\n";
        cout << "3. Remove students" << "\n";
        cout << "4. Exit" << "\n";
        cout << "Your choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            schoolSystem.viewStudents();
            break;
        case 2: 
            schoolSystem.addStudent();
            break;
        case 3:
            schoolSystem.removeStudent();
            break;
        case 4:
            cout << "Exit the program!" << "\n";
            exit(0);
        default:
            cout << "Invalid choice, please choose again!";
            break;
        }
    } while(choice == 1 || choice == 2 || choice == 3 || choice == 4);
    return 0;
};