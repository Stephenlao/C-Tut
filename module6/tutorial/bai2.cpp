    #include <iostream>
    #include <vector>
    #include <limits>
    #include <fstream>
    using namespace std;

    class Student {
        private:
            string name;
            int studentID;
        
        public:
        // initialize constructor as member initializer
            Student(string name_val = "", int studentID = 0) : name(name_val), studentID(studentID) {
            };

        // destructor when object is out of scope
            ~Student() {
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
    // A virtual function in C++ is a member function of a base class that can be overridden in a derived class. 
    // The primary purpose of virtual functions is to support polymorphism, 
    // allowing a base class pointer (or reference) to call the appropriate function depending on the type of the object it points to (or references).
            virtual string toString() {
                return "Name: " + name + " "+ "StudentID: " + to_string(studentID);
            };
    };

    class SchoolSystem {
        private:
        std::vector<Student> students;
        ifstream infile;

        public:
            SchoolSystem() {};
            void addStudent() { 
                string name;
                int studentID;  
                cout <<"Enter student name: ";
                cin.ignore(1, '\n'); // ignore the '\n'
                getline(cin, name); // because name has space => get all line

                cout <<"Enter studentID: ";
                cin >> studentID;
                Student student(name, studentID);
                students.push_back(student);
                cin.clear(); // clear student object to avoid an error: ex: when saving student object in students vector array
                // it brings this array and come back to while loop and assign it to 'choice' variable which is invalid input
                // because choice is integer. Thus we need to clear input 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            };

            void removeStudent() {
                int studentID;

                cout << "Enter studentID for deleting: ";
                cin >> studentID;

            int removeIdx;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getStudentID() == studentID) {
                    removeIdx = i;
                }
            };

            if (removeIdx != -1) {
                students.erase(students.begin()+ removeIdx); 
                // erase accept two params 1. student/begin() target to
                // first element of students vector array which is student object.
                // 2. second params accept int value. RemoveIdx is index of elements for deletion
                cout << "Remove student successfully!" << "\n";
            } else {
                cout << "StudentID is incorrect!" << "\n";
            }
            };

       void displayStudents() {
        ifstream infile("student.dat");  // Declare and open the file at the same time

        if (!infile.is_open()) {  // Check if the file has been successfully opened
            cout << "File does not exist or cannot be opened!\n";
            return;  // Exit the function
        }

        if (infile.peek() == ifstream::traits_type::eof()) { // check whether data has in file
            cout << "There is no data within student.dat!\n";
            infile.close();
            return;  // Exit the function
        }

        string prefix;
        string name;
        int studentID;

        while (true) {
            // Read "Name:" prefix
            infile >> prefix;
            if (!infile) break;  // Break out of the loop if reading failed (end of file reached)

            // Read the name until "StudentID:"
            getline(infile, name, 'S');  // Delimiter set to 'S' assuming "StudentID:" comes next
            infile >> prefix;  // Read "StudentID:"

            // Remove trailing spaces from the name (caused by reading up to 'S')
            name = name.substr(0, name.length() - 1);

            // Read student ID
            infile >> studentID;

            cout << "Name: " << name << ", Student ID: " << studentID << "\n";
        }

            infile.close();  // Close the file after use
        };
            vector<Student> getStudentsArray() {
                return students;
            };

            void setStudents(vector<Student> studs) {
                this ->students = studs;
            };
};

        
int main() {
    SchoolSystem schoolsystem; // Create this outside the loop to retain changes across iterations
    ofstream outfile;
    int exit = 0;
    int choice;

    while (exit == 0) {
        cout << "School Management System" << "\n";
        cout << "1. View all students" << '\n';
        cout << "2. Add Student" << "\n";
        cout << "3. Remove Student" << "\n";
        cout << "4. Exit" << "\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            schoolsystem.displayStudents();
            break;
        case 2:
            schoolsystem.addStudent();
            break;
        case 3:
            schoolsystem.removeStudent(); // Assuming you have this function in your SchoolSystem class
            break;
        case 4:
            outfile.open("student.dat");
            if (!outfile.is_open()) {
                cout << "File name is incorrect!";
            } else {
                for (Student student : schoolsystem.getStudentsArray()) {
                    outfile << student.toString() << "\n"; 
                }
            };
            exit = 1;
            break; // Exit the program
        default:
            cout << "Invalid choice";
            break;  // Recommended to add a break statement even if it's the last case
        };
    };
    return 0;  // It's good practice to have a return statement at the end of main
};
