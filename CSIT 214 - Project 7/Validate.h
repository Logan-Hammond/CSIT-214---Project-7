// Author       : Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File  : Validate.h
// Description  : 
// IDE Used     : Microsoft Visual Studio 2017

#include <string>
#pragma once
using namespace std;


class Validate {
public:
	Validate();
	Validate(string s);
	~Validate();
	void displayMsg();
	bool checkLength();
	bool checkSpaces();
	bool checkUpper();
};
