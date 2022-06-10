#include <iostream>

using namespace std;

void nilai (int nilai) {
	cout << "Nilai anda " << nilai << endl;
	if (nilai >= 75) {
		cout << "Anda mendapat grade A";
	} else if (nilai >= 65 && nilai <= 75) {
		cout << "Anda mendapat grade B";
	} else if (nilai >= 50 && nilai <= 64) {
		cout << "Anda mendapat grade C";
	} else if (nilai >= 25 && nilai <= 49) {
		cout << "Anda mendapat grade D";
	} else if (nilai >= 0 && nilai <= 24) {
		cout << "Anda mendapat grade E";
	} 
	
}

int main () {
	nilai (76);
	return 0;
}
