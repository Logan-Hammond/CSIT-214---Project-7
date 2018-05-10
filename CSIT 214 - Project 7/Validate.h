// Author       : Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File  : Validate.h
// Description  : Header file for Validate class. 
// IDE Used     : Microsoft Visual Studio 2017

#include <string> // 'string' data type.
#pragma once

class Validate {
public:
	Validate();              // Default constructor. Why does this need to exist? 
	Validate(std::string s); // Constructor.
	~Validate();             // Destructor.
	void displayMsg();       // Displays password rules.
	bool checkLength();      // Checks password length.
	bool checkSpaces();      // Checks if password has spaces.
	bool checkUpper();       // Checks if password has at least one uppercase character.
};
