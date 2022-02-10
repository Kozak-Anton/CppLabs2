#include "lib.h"

void inputFile(const char* fileName) {
	medication ampule;
	ofstream file(fileName, ios::binary);
	int num, addHours;


	cout << "Enter number of ampules: "; cin >> num; cout << endl;
	if (num <= 0) cout << "Error, no information given" << endl;
	for (int i = 0; i < num; i++) {
		cout << "Name: "; cin >> ampule.name;
		cout << "Hours: "; cin >> ampule.hours;
		cout << "Minutes: "; cin >> ampule.minutes;
		cout << "Days stored: "; cin >> ampule.daysStored;
		cout << "Days can be stored: "; cin >> ampule.daysMax;
		cout << endl;

		if (ampule.minutes >= 60) {
			addHours = ampule.minutes / 60;
			ampule.hours += addHours;
			ampule.minutes -= addHours * 60;
		}
		if (ampule.hours > 99) ampule.hours = 99;

		file.write((char*)&ampule, sizeof(medication));
	}

	file.close();
}

void outputFile(const char* fileName) {
	medication ampule;
	ifstream file(fileName, ios::binary);

	while (file.read((char*)&ampule, sizeof(medication))) {
		if (ampule.daysMax - ampule.daysStored < 0) cout << "AMPULE EXPIRED!"<<endl;
		else if (ampule.daysMax - ampule.daysStored < 10) cout << "AMPULE ALMOST EXPIRED!" << endl;
		cout << "Name: "<<ampule.name<<endl;
		cout << "Effective after opening for: " << ampule.hours << "h:" << ampule.minutes <<"m" << endl;
		cout << "Stored for: " << setprecision(1) << ampule.daysStored/365. << " years" << endl;
		cout << "Can be stored for: " << setprecision(1) << ampule.daysMax / 365. << " years" << endl;
		cout << endl;
	}
	file.close();

}

void removeData(const char* fileName) {

	const char* tempName = "temp.txt";
	medication ampule;
	ofstream tempFile(tempName, ios::binary);
	ifstream file(fileName, ios::binary);

	while (file.read((char*)&ampule, sizeof(medication))) {
		if (ampule.daysStored <= 365) {
			tempFile.write((char*)&ampule, sizeof(medication));
		}
	}
	tempFile.close();
	file.close();

	remove(fileName);
	rename(tempName, fileName);

}


