#include "lib.h"

void inputFile(string fileName) {
	medication ampule;
	ofstream file(fileName, ios::binary);
	int num, addHours;


	cout << "Number of ampules: "; cin >> num; cout << endl;
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

void outputFile(string fileName) {
	medication ampule;
	ifstream file(fileName, ios::binary);

	while (file.read((char*)&ampule, sizeof(medication))) {
		if (ampule.daysMax - ampule.daysStored < 10) {
			cout << "AMPULE ALMOST EXPIRED!"<<endl;
		}
		cout << "Name: "<<ampule.name<<endl;
		cout << "Effective after opening for: " << ampule.hours << "h:" << ampule.minutes <<"m" << endl;
		cout << "Stored for: " << setprecision(1) << ampule.daysStored/365. << " years" << endl;
		cout << "Can be stored for: " << setprecision(1) << ampule.daysMax / 365. << " years" << endl;
		cout << endl;
	}
	file.close();

}

void removeData(string fileName) {
	void removeEntry(string, int);

	medication ampule;
	ifstream file(fileName, ios::binary);
	int pos=0;

	while (file.read((char*)&ampule, sizeof(medication))) {
		if (ampule.daysStored > 365) {
			removeEntry(fileName, pos);
		}
		pos++;
	}

}
//TEST
void print(medication ampule) {
	cout << endl << "FILEWORK";
	cout << "Name: " << ampule.name << endl;
	cout << "Effective after opening for: " << ampule.hours << "h:" << ampule.minutes << "m" << endl;
	cout << "Stored for: " << setprecision(1) << ampule.daysStored / 365. << " years" << endl;
	cout << "Can be stored for: " << setprecision(1) << ampule.daysMax / 365. << " years" << endl;
	cout << endl;
}

void removeEntry(string fileName, int pos) {
	medication ampule;
	ifstream iFile(fileName, ios::binary);
	ofstream oFile(fileName, ios::binary);


	iFile.close();
	oFile.close();

}