#include "lib.h"

void inputFile(const char* fileName) {
	ofstream file(fileName);
	string input;
	getline(cin, input);
	while (!input.empty()) {
		file << input << endl;
		getline(cin, input);

	}
	file.close();
}

void printFile(const char* fileName) {
	ifstream file(fileName);
	string line;
	while (!file.eof()) {
		getline(file, line);
		cout << line << endl;
	}
	file.close();
}

void rewriteFile(const char* initFile, const char* editFile) {

	ofstream oFile(editFile);
	ifstream iFile(initFile);

	string line;
	int count = 0;
	while (!iFile.eof()) {
		count++;
		getline(iFile, line);
		if (line.empty()) break;
		oFile << count << ". " << line << " " << line.length() << endl;
	}
	oFile.close();
	iFile.close();
}
