#include "BST.h"

int main() {
	fstream morseTable;
	morseTable.open("MorseTable.txt");

	BST<morse> translate(morseTable);

	morseTable.close();

	cout << "character:     Morse string:  " << endl;
	translate.displayTree();

	fstream convert;
	convert.open("translate.txt");

	while (!convert.eof()) {
		char a = '\0';
		convert.get(a);
		if (a == '\n') {
			cout << "\n"<<endl;
		}
		else if (a == '\0') {
			cout << "";
		}
		else if (a == ' ') {
			cout << " ";
		}
		else {
			morse searchValue(toupper(a));
			morse lookup = translate.search(searchValue);
			cout << lookup.getMorse()<< " ";
		}
	}
	cout << endl;
	convert.close();
	return 0;
}