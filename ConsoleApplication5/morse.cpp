#include "morse.h"

morse::morse(char newAlpha, string newMorse) {
	this->alphaChar = newAlpha;
	this->morseStr= newMorse;
}

morse::morse(morse &copy) {
	this->setAlpha(copy.getAlpha());
	this->setMorseString(copy.getMorse());
}

morse::~morse() {

}

char morse::getAlpha() const {
	return this->alphaChar;
}

void morse::setAlpha(const char &alpha) {
	this->alphaChar = alpha;
}

string morse::getMorse()const {
	return this->morseStr;
}

void morse::setMorseString(const string &morseString) {
	this->morseStr = morseString;
}

morse & morse::operator=(morse &rhs) {
	this->setAlpha(rhs.getAlpha());
	this->setMorseString(rhs.getMorse());
	return (*this);
}

ostream &operator<<(ostream &lhs, const morse &rhs) {
	lhs << "\t" << rhs.getAlpha() << "\t" << rhs.getMorse() << endl;
	return lhs;
}

fstream & operator >> (fstream &lhs, morse &rhs) {
	char a= '\0', space = '\0', morse[MAX_LEN] = "";
	lhs.get(a);
	lhs.get(space);
	lhs.getline(morse, MAX_LEN);
	string morse_str = morse;

	rhs.setAlpha(a);
	rhs.setMorseString(morse_str);
	return lhs;
}

bool operator>(morse &lhs, morse &rhs) {
	bool truth = false;
	if (lhs.getAlpha() > rhs.getAlpha()) {
		truth = true;
	}
	return truth;
}

bool operator< (morse &lhs, morse &rhs) {
	bool truth = false;
	if (lhs.getAlpha() < rhs.getAlpha()) {
		truth = true;
	}
	return truth;
}

bool operator ==(morse &lhs, morse &rhs) {
	bool truth = false;
	if (lhs.getAlpha() == rhs.getAlpha()) {
		truth = true;
	}
	return truth;
}

bool operator!=(morse &lhs, morse &rhs) {
	bool truth = false;
	if (lhs.getAlpha() != rhs.getAlpha()) {
		truth = true;
	}
	return truth;
}
