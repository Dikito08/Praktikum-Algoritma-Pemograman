#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

int main () {
	system ("color 5e");
	
	int pilih, lagi;
	a:
		cout << "Selamat datang di game suit" << endl;
		cout << "Kamu pilih?\n\n";
		cout << "1. Gajah\n2. Semut\n3. Orang\n";
		cout << "Silahkan Pilih : ";
		cin >> pilih;
		cout << endl;
		
		if (pilih == 1) {
			cout << "Kamu memilih gajah\n";
			srand(time(NULL));
			int com = rand() % 10;
			if (com <= 3 && com >= 1)
			{
				cout << "Computer = Gajah\n\n";
				cout << "Seri\n"; 
			} else if (com <=6 && com >=4)
			{
				cout << "Computer = Orang\n";
				cout << "Kamu menang\n";
			} else 
			{
				cout << "Computer = Semut";
				cout << "Kamu kalah\n";
			} cout << endl;
		}
		else if (pilih == 2){
			cout << "Kamu memilih semut\n";
			srand(time(NULL));
			int com = rand() % 10;
			if (com <= 3 && com >= 1)
			{
				cout << "Computer = Semut\n\n";
				cout << "Seri\n"; 
			} else if (com <=6 && com >=4)
			{
				cout << "Computer = Gajah\n";
				cout << "Kamu menang\n";
			} else 
			{
				cout << "Computer = Orang\n";
				cout << "Kamu kalah\n";
			} cout << endl;
		}
		else if (pilih == 3) {
			cout << "Kamu memilih orang\n";
			srand(time(NULL));
			int com = rand() % 10;
			if (com <= 3 && com >= 1)
			{
				cout << "Computer = Orang\n\n";
				cout << "Seri\n"; 
			} else if (com <=6 && com >=4)
			{
				cout << "Computer = Semut\n";
				cout << "Kamu menang\n";
			} else 
			{
				cout << "Computer = Gajah";
				cout << "Kamu kalah\n";
			} cout << endl;
		}
		else {
			cout << "Nomor yang anda input salah" << endl;
		}
		
		cout << "Pilih lagi = [0] : ";
		cin >> lagi;
		b:
			if (lagi == 0){
				system ("cls");
				goto a;
			}
}
