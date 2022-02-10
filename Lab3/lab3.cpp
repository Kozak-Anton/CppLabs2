#include <fstream>
#include <iostream>

using namespace std;

int main() {
	fstream file("text.txt",ios::out|ios::in|ios::binary);
	if (file.is_open()) {
		cout << "YES";
	}
	file.close();
}