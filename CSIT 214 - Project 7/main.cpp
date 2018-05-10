// Author       : Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File  : main.cpp
// Description  : 
// IDE Used     : Microsoft Visual Studio 2017

#include <iostream>
#include <string>
#include <vector>
#include "Validate.h"
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
	while (firstName != "0") {  // Loop does not start when '0' is entered for first name. 
		cout << "\tLast Name : ";
        getline(cin, lastName);

        Validate message(""); // Can't call objects functions using default constructor.
        message.displayMsg(); 

        // Password validation. 
        do {
            cout << "\n\n\tEnter Password: ";
            getline(cin, password);
            Validate passwordV(password); 
            
            // Seperate bools for each condition.
            bool isShort, hasSpaces, hasCaptial;
            isShort = passwordV.checkLength();
            if (!isShort) {
                passwordHasError = true;
            }
            hasSpaces = passwordV.checkSpaces();
            if (hasSpaces) {
                passwordHasError = true;
            }
            hasCaptial = passwordV.checkUpper();
            if (!hasCaptial) {
                passwordHasError = true;
            }

            if (passwordHasError) {
                cout << "\n\tPlease choose another password.";
            }

            /*
            if (!passwordV.checkLength() || passwordV.checkSpaces() || passwordV.checkUpper()) {
                passwordHasError = true; 
                cout << "\n\tPlease try a different password."; 
            }
            else {
                passwordHasError = false; 
            }
            */

        } while (passwordHasError); 

        // Password confirmation. 
        /*
        do {
            cout << "\tRe-enter Password: ";
            cin >> confirmationPass;
            if (confirmationPass != password) {
                cout << "\n\tPasswords do not match. Please try again.\n";
            }
        } while (confirmationPass != password);
        */

        string login = firstName.substr(0, 1) + lastName.substr(0, 5) + ", " + password;
		loginVector.push_back(login);
		cout << "\n\tFirst Name: ";
		cin >> firstName;
	} 

    // Displays elements of loginVector.
    int loginElement = 0;
    for (vector<string>::iterator it = loginVector.begin(); it != loginVector.end(); ++it) {
        cout << "\n\tLogin " << (loginElement + 1) << ": " << loginVector[loginElement];
        loginElement++;
    }

	cout << "\n\n\t";
	system("pause");
	return 0;
}
