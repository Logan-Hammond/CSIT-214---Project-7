// Author       : Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File  : main.cpp
// Description  : Prompts user for usernames and passwords and stores those credentials in a vector arary.
//                  Contents of array are displayed when user exits program.
// IDE Used     : Microsoft Visual Studio 2017

#include "Validate.h" // Object to validate password.
#include <iostream>   // I/O. 
#include <string>     // 'string' data type. 
#include <vector>     // Vectors. 
using namespace std;

int main() {
	string firstName = "";
	string lastName = "";
	string password = "";
	string confirmationPass = "";
	vector<string> loginVector;
    bool passwordHasError = false;

	cout << "\n\tFirst Name: ";
    getline(cin, firstName);
    
    // Contains password intput, validation, and confirmation. 
	while (firstName != "0") {  // Loop does not start when '0' is entered for first name. 
		cout << "\tLast Name : ";
        getline(cin, lastName);

        // Can't call objects functions using default constructor.
        Validate message(""); 
        message.displayMsg(); 

        // Password validation. 
        do {
            cout << "\n\n\tEnter Password: ";
            getline(cin, password);

            Validate passwordV(password);
            bool isLongEnough, hasSpaces, hasUppercase;
            isLongEnough = passwordV.checkLength();
            hasSpaces = passwordV.checkSpaces();
            hasUppercase = passwordV.checkUpper();
            if (!isLongEnough || hasSpaces || !hasUppercase) {
                passwordHasError = true;
                cout << "\n\tPlease choose another password.";
            }
            else {
                passwordHasError = false;
            }
        } while (passwordHasError); 

        // Password confirmation. 
        do {
            cout << "\tRe-enter Password: ";
            getline(cin, confirmationPass);
            if (confirmationPass != password) {
                cout << "\n\tPasswords do not match. Please try again.\n";
            }
        } while (confirmationPass != password); 

        // Create credential and store. 
        string login = firstName.substr(0, 1) + lastName.substr(0, 5) + ", " + password;
		loginVector.push_back(login);

		cout << "\n\tFirst Name: ";
        getline(cin, firstName);
	} 

    // Displays elements of vector.
    cout << "\n\n\t\tCREDENTIALS LIST\n";
    int loginElement = 0;
    for (vector<string>::iterator it = loginVector.begin(); it != loginVector.end(); ++it) {
        cout << "\n\tLogin " << (loginElement + 1) << ": " << loginVector[loginElement];
        loginElement++;
    }

	cout << "\n\n\t";
	system("pause");
	return 0;
}
