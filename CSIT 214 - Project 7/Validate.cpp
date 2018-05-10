// Author       : Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File  : Validate.cpp
// Description  : 
// IDE Used     : Microsoft Visual Studio 2017

#include "Validate.h" 
#include <iostream> 
#include <string> 
#include <cctype> // isupper function.
using namespace std; 

// Array containing error messages. 
string errorArray[3] = { "Error: Password must be at least six characters.", "Error: Password can not contain any spaces.",
                            "Error: Password must have at least one uppercase character." };
const int LEN = 6;	// Minimum password length.
string entry;

// Constructors and destructor. 
Validate::Validate(string s) {
	entry = s;
}
Validate::Validate() {}
Validate::~Validate() {} 


/*
	Displays rules for password creation.
	@return void.
*/
void Validate::displayMsg() {
	cout << "\n\tYour password must...";
	cout << "\n\t    -Be at least six characters long.";
	cout << "\n\t    -Not contain any spaces.";
	cout << "\n\t    -Contain at least one uppecase character.";
}

/*
    Checks length of password.
    @return TRUE if password is sufficient length; FALSE otherwise.
*/
bool Validate::checkLength() {
	if (entry.length() < 6) {
		cout << "\n\t" + errorArray[1];
		return true;
	}
	return false;
}

/*
    Checks if password contains any spaces.
    @return TRUE if password contains any spaces; FALSE otherwise.
*/
bool Validate::checkSpaces() {
	for (int i = 0; i < entry.length(); i++) {
		if (entry[i] == ' ') {
			cout << "\n\t" + errorArray[2];
			return true;
		}
	}
	return false;
}

/*
    Checks if password contains at least one uppercase character.
    @return TRUE if password contains at least one uppercase character. FALSE otherwise.
*/
bool Validate::checkUpper() {
	bool hasUppercaseChar = false;
	
	for (int i = 0; i < entry.length(); i++) {
		if (isupper(entry[i])) {
			hasUppercaseChar = true;
		}
	}
	return hasUppercaseChar;
}
