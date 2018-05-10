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
	string login = "";
	vector<string> loginVector;
    bool passHasError = true;

	cout << "\n\tFirst Name: ";
	cin >> firstName;
	while (firstName != "0") {
		cout << "\tLast Name : ";
		cin >> lastName;

        Validate message("");
        message.displayMsg();
        cout << "\n\n\tEnter Password: ";
        cin >> password;
        do {
            cout << "\tRe-enter Password: ";
            cin >> confirmationPass;
            if (confirmationPass != password) {
                cout << "\n\tPasswords do not match. Please try again.\n";
            }
        } while (confirmationPass != password);

        // Password validation goes here 
        do {
            Validate message("");
            message.displayMsg();
            cout << "\n\n\tEnter Password: ";
            cin >> password;

            Validate password(password);
            if (password.checkLength() || password.checkSpaces() || password.checkUpper()) {
                passHasError = true;
                cout << "\n\tPlease try a different password.";
            }
            else {
                passHasError = false;
            }
        } while (passHasError);


		login = firstName.substr(0, 1) + lastName.substr(0, 5) + ", " + password;
		loginVector.push_back(login);
		cout << "\n\tFirst Name: ";
		cin >> firstName;
	} 

    // Displays elements of loginVector. Humanly readable.
    int i = 0;
    for (vector<string>::iterator it = loginVector.begin(); it != loginVector.end(); ++it) {
        cout << "\n\tLogin " << i+1 << ": " << loginVector[i];
        i++;
    }

	cout << "\n\n\t";
	system("pause");
	return 0;
}
