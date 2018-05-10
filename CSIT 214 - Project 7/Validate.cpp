// Author       : Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File  : Validate.cpp
// Description  : 
// IDE Used     : Microsoft Visual Studio 2017

#include "Validate.h"   // Function declarations in header. 
#include <iostream>     // I/O. 
#include <string>       // 'string' data type. 
#include <cctype>       // 'isupper' function. 
using namespace std; 

// Array containing error messages. 
string errorArray[3] = { "Error: Password must be at least six characters.", "Error: Password can not contain any spaces.",
                            "Error: Password must have at least one uppercase character." };
const int LEN = 6;	// Minimum password length.
string entry = "";  // Global password string.


// Constructors and destructor. 
Validate::Validate(string s) {
	entry = s;
}
Validate::Validate() {}
Validate::~Validate() {}

// Function definitions. 
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
    Determines if password is of sufficient length.
    @return TRUE if password is sufficient length; FALSE otherwise.
*/
bool Validate::checkLength() {
    bool hasAppropriateLength = false;
    if (entry.length() >= LEN) { 
        hasAppropriateLength = true;
    }
    else {
        cout << "\n\t" + errorArray[0];
    }
	return hasAppropriateLength;
}

/*
    Determines if password contains any spaces. 
    @return TRUE if password contains any spaces; FALSE otherwise.
*/
bool Validate::checkSpaces() { 
    bool hasSpaces = false;
    for (int i = 0; i < entry.length(); i++) {
		if (isspace(entry[i])) {
			hasSpaces = true;
        }
	}
    if (hasSpaces) {
        cout << "\n\t" + errorArray[1];
    }
	return hasSpaces;
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
    if (!hasUppercaseChar) {
        cout << "\n\t" + errorArray[2];
    }
	return hasUppercaseChar;
}
