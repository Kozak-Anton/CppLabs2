#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct medication { //характеристики ампули
	char name[20];  //ім'я
	int hours;      //годин дії
	int minutes;    //хвилин дії
	int daysStored; //днів зберігання 
	int daysMax;    //срок придатності
};

void inputFile(const char*);  //введення спику
void outputFile(const char*); //виведення списку
void removeData(const char*); //видалення зайвих ампул
