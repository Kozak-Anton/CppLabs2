#include "lib.h"

int main() {
	string list = "medicine list.txt";
	cout << "Input list information: "<<endl;
	inputFile(list);
	removeData(list);
	cout << endl <<"Edited medicine list: " << endl;
	outputFile(list);

}