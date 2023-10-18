#include <iostream>
#include <cstring>

using namespace std;

// ONLY USE char *argv[] in COMMAND LINE ARGUMENT
//argc => argument count, argv => argument vector (array of string)

int main(int argc, char *argv[]) {

    //if input arguments, argc is not equal to 2, then program exit with an error message 
    // argc != 2 to check the input should have at least 1 argument
    // argc == 2 because first argc (argc[0]) is the name of system.Thus, we need to start in second argc which is argc[1]
    // argc == 2 runs like loop go through 0 and 1.
    if(argc != 2) {
        cerr << "Should pass at least 1 argument";
        return -1;
    }

    //valid is set to 1 initially to denote that it's a valid hexadecimal number
    //if it's not a valid hexadecimal number, then valid is set to 0.
    int valid = 1;
        
    //check for 4 digit first. If it's not, valid is set to 0 in the else.
    if (strlen(argv[1]) == 4) {
        if (argv[1][0] != '0') {  //if the first digit is not '0', set valid to 0.
            valid = 0;
        }
        if ((argv[1][1] != 'x' && argv[1][1] != 'X')) { //if the second digit is not 'x' or 'X', set valid to 0.
            valid = 0;
        }

        //check for the remaining digit to make sure that it's in the range of either '0' to '9' or 'A' to 'F'.
        //if it's not, set valid to 0, and exit the for loop immediately.
        for (int i = 2; i < strlen(argv[1]); i++) {
            if (!((argv[1][i] >= '0' && argv[1][i] <= '9') || (argv[1][i] >= 'A' && argv[1][i] <='F'))) {  // Fixed the bracketing error and added the right conditions
                valid = 0;
            }
        }
    } else {
        valid = 0;
    }

    //test the valid value. If valid is still 1, then it's a valid hexadecimal number, else it's not.
    if (valid == 1) {  // Fix the comparison
        cout << "Valid hexadecimal";
    } else {
        cout << "Invalid hexadecimal";  // Add the missing semicolon
    }
    return 0;
}
