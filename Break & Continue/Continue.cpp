#include <iostream>
#include <conio.h>

using namespace std;

struct peserta_t {
	int id;
	string nama;
	string urusan;
	int dosisvaksin;
};

int main (){
	peserta_t peserta[] {
	{
		1, 
		"Ipin", 
		"Main", 
		1
	},
	{
		2, 
		"Wildan",
		"Belajar",
		2
	},
	{
		3,
		"Inayah",
		"Belanja",
		1
	},
	{
		4,
		"Puja",
		"Pinjambuku",
		3
	},
	{
		5,
		"Arkan",
		"Belanja",
		1
	}
	};
	
	int minimaldosisvaksin = 2;
	
	cout << "Pemeriksaan dosis vaksin!\n" << endl;
	
	for (int i = 0;i < 5;i++) {
		if (peserta[i].dosisvaksin < minimaldosisvaksin) {
			continue;
		}
		cout << "Silahkan, saudara " << peserta[i].nama << " Boleh masuk" << endl;
	}
	return 0;
}
