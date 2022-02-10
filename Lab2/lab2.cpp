/*Козак А.М. ІП 13
* Варіант 17
Створити файл зі списком лікарських ампул: назваб термін дії(ГГ:ХХ), термін зберігання(р). Видалити інформацію про ампули, термін зберігання яких > 1р.
Видати попередження про закінчення терміну зберігання за 10 днів.*/

#include "lib.h"

int main() {
	const char* list = "medicine list.txt";   //назва списку
	cout << "Input list information: "<<endl;
	inputFile(list);
	removeData(list);
	cout << endl <<"Edited medicine list: " << endl;
	outputFile(list);

}