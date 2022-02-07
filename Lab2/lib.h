#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct medication {
	char name[20];
	int hours;
	int minutes;
	int daysStored;
	int daysMax;
};

void inputFile(string);
void outputFile(string);
void removeData(string);
