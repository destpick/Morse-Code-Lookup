#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::ostream;
using std::fstream;
using std::endl;

#define MAX_LEN 15

class morse {
private:
	char alphaChar;
	string morseStr;

public:
	morse(char newAlpha = '\0', string newMorse = "");
	morse(morse &copy);
	~morse();
	char getAlpha() const;
	void setAlpha(const char &alpha);
	string getMorse() const;
	void setMorseString(const string &morse);

	morse & operator=(morse &rhs);
};

bool operator!=(morse &lhs, morse &rhs);



ostream & operator<<(ostream &lhs, const morse &rhs);

bool operator>(morse &lhs, morse &rhs);

fstream &operator >> (fstream &lhs, morse &rhs);

bool operator<(morse &lhs, morse &rhs);

bool operator==(morse &lhs, morse &rhs);

