/*Козак А.М. ІП 13
* Варіант 17
* Створити текстовий файл. Переписати його компоненти до нового текстового файлу, вставляючи на початку рядка порядковий номер,
в кінці рядка - поточну довжину рядка у вихідному файлі. Вивести вміст вихідного і створеного файлів. */
#include "lib.h"

int main() {
	const char* initFile = "initText.txt"; //початковий файл
	const char* editFile = "editText.txt"; //відредагований файл

	cout << "Input initial text here: " << endl;
	inputFile(initFile);
	rewriteFile(initFile, editFile);
	cout << "Edited text: " << endl;
	printFile(editFile);

}