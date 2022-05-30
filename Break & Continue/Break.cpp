#include <iostream>
#include <conio.h>

using namespace std;

struct peserta_t {
	int id;
	string nama;
	string asaldaerah;
	int tinggibadan;
};

int main (){
	peserta_t peserta[] {
	{
		1, 
		"Jojo", 
		"Garut", 
		158
	},
	{
		2, 
		"Nopal",
		"Sukabumi",
		160
	},
	{
		3,
		"Budi",
		"Tasik",
		155
	},
	{
		4,
		"Anton",
		"Bogor",
		180
	},
	{
		5,
		"Budi",
		"Bandung",
		168
	}
	};
	
	int minimaltinggi = 175;
	
	cout << "Hasil seleksi tentara berdasarkan tinggi badan!\n" << endl;
	
	for (int i = 0;i < 5;i++) {
		if (peserta[i].tinggibadan >= minimaltinggi) {
			cout << "Selamat saudara " << peserta[i].nama << " dinyatakan lulus seleksi\n";
			break;
		}
		cout << "Maaf saudara " << peserta[i].nama << " dinyatakan tidak losos seleksi " << endl;
	}
	return 0;
}
