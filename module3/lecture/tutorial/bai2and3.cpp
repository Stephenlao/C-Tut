#include <iostream>
#include <fstream>
using namespace std;

class Student {
    private: 
        int score;
        string password;

    public:
        string name;
        
        // initialise constructor
        Student (string name_val, int score_val) {
        name = name_val;
        score = score_val;
    };

    // create method get_score() to get access into it
        int get_score() {
            return score;
        };
    // method changePwd accepts two params: userFile which is user's input file, and other is newPassword
        void changePwd(string userFile, string newPassword) {
            ifstream myfile1;  // myfile1 is ifstream which is in Read file mode.  
            ofstream myfile2;  // myfile2 is ifstream which is in Write file mode. 
            string content, oldPassword;
            string file = userFile + ".dat";

            // Open 'file' for reading
            myfile1.open(file);
            // Check whether it is successfully open using is_open()
            if (!(myfile1.is_open())) {
                cout << "There is no file related to" << file << "yet" << "\n";
                cout << "Your password is saved in " << file << "\n";
                myfile2.open(file); // Open 'file' for writing
                myfile2 << newPassword; // save newPassword params to myFile2
                password = newPassword; // assign back to attributes
                myfile2.close();
                cout << "Your new password is saved successfully" << "\n";
            }
            else { 
                myfile1 >> content; // read password stored in myfile1 and assign to content
                myfile1.close();

                if (content.length() == 0) { // check if there is no password in content
                    cout << "There is no password in " << file;
                    myfile2.open(file); 
                    myfile2 << newPassword; // save to myfile2 
                    password = newPassword;
                    myfile2.close();
                    cout << "Your new password is saved successfully" << "\n";
                } else { // if have password inside 'file'
                    cout << "Please enter your previous password for verification: ";
                    cin >> oldPassword;

                    if (oldPassword == content) { // check whether user's password is equal to content
                        myfile2.open(file);
                        myfile2 << newPassword;
                        password = newPassword;
                        myfile2.close();
                        cout << "Your new password is saved successfully" << "\n";
                    } else {
                        cout << "Your password is incorrect!" << "\n";
                    }
                }
            }
        }
};

int main() {
    // 2b
    Student student1("Khang",9);
    Student student2("Uyen", 8);

    //score attribute is private, thus using get_score method 

    cout << "Student 1 information: " << " " << student1.name << "," << "score: " << student1.get_score() << "\n";
    cout << "Student 2 information: " << " " << student2.name << "," << "score: " << student2.get_score() << "\n";

    // 2c
    // Create an student_arr
    Student student_arr[3] = {  Student("Khanh",7),
                                Student("Khang", 9),
                                Student("Uyen", 8)
                            };
    // get first student score in arr to start comparing 
    int max_student_score = student_arr[0].get_score();

    // declare max_student_index to later on when finding highest student score then extract student object
    int max_student_index;
    for (int i = 0; i < 3; i++) {
        if (max_student_score < student_arr[i].get_score()) {
            max_student_score = student_arr[i].get_score();
            max_student_index = i;
        }
    };
    cout <<"Student information highest score: " << " " << student_arr[max_student_index].name << " " << student_arr[max_student_index].get_score() << "\n";

    // 2c

    Student s3("Duc", 6);

    string password;
    cout << "Enter new password: ";
    getline(cin, password );
    s3.changePwd("DucOcCho",password);
}