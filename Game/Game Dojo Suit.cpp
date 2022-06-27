#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27

void setcolor (unsigned short color)
{
  HANDLE hCon = GetStdHandle (STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute (hCon, color);

}

const int panjangpeta = 20;
const int lebarpeta = 20;
int koordinatX = 0;
int koordinatY = 8;
int arrowKey = ' ';

// map
int peta[lebarpeta][panjangpeta] = {
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    {4, 2, 1, 1, 1, 1, 5, 6, 5, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 4},
    {4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 5, 5, 5, 5, 1, 1, 5, 5, 5, 5, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 2, 1, 1, 6, 1, 1, 6, 1, 1, 2, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 6, 1, 1, 6, 1, 1, 1, 4},
    {4, 5, 5, 5, 5, 5, 5, 1, 5, 1, 1, 1, 6, 1, 1, 6, 1, 1, 1, 4},
    {1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 6, 1, 1, 6, 1, 1, 1, 4},
    {1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 5, 5, 5, 5, 5, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 4},
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
	};

// movement
void playermove (int key) {
	if (arrowKey == KEY_UP
	  && peta[koordinatY - 1][koordinatX] < 4)
	{
	  koordinatY -= 1;
	  koordinatY < 0 ? koordinatY =
	    0 : koordinatY;
	}
      else if (arrowKey == KEY_DOWN
	       && peta[koordinatY + 1][koordinatX] < 4)
	{
	  koordinatY += 1;
	  koordinatY > 15 ? koordinatY =
	    15 : koordinatY;
	}
      else if (arrowKey == KEY_LEFT
	       && peta[koordinatY][koordinatX - 1] < 4)
	{
	  koordinatX -= 1;
	  koordinatX < 0 ? koordinatX =
	    0 : koordinatX;
	}
      else if (arrowKey == KEY_RIGHT
	       && peta[koordinatY][koordinatX + 1] < 4)
	{
	  koordinatX += 1;
	  koordinatX > 19 ? koordinatX =
	    19 : koordinatX;
	}
      else
	{
	  // nothing to do
	};
}

void mapdisplay () {
	int koordinat = peta[koordinatY][koordinatX];
	
	for (int i = 0; i < lebarpeta; i++)
	{
	  for (int j = 0; j < panjangpeta; j++)
	    {
	      if (koordinatX == j && koordinatY == i
		  && koordinat < 4)
		{
		  setcolor (13);	//warna pink
		  cout << "$";		//player
		  setcolor (7);
		}
	      else if (peta[i][j] == 1)
		{
		  setcolor (11);	//warna cyan	
		  cout << "_";		//jalan
		  setcolor (7);
		}
	      else if (peta[i][j] == 2)
		{
		  setcolor (4);		//warna merah
		  cout << "!";		//orang atau musuh
		  setcolor (7);
		}
	      else if (peta[i][j] == 4)
		{
		  setcolor (2);		//warna hijau
		  cout << "=";		//tembok
		  setcolor (7);
		}
	      else if (peta[i][j] == 5)
		{
		  setcolor (1);		//warna biru
		  cout << "-";		//kayu
		  setcolor (7);
		}
	      else if (peta[i][j] == 6)
		{
		  setcolor (8);		//warna abu-abu
		  cout << "o";		//batu
		  setcolor (7);
		}
	    }
	  cout << "\n";
	};
}
int main ()
{
  // Game dojo suit
  /*
     1 jalan biasa : _
     2 orang : !
     4 tembok : =
     5 kayu : -
     6 Batu : o
  */
	int game = 1;
	while (game <= 1)
    {
      // Input Keyboard
      main :
	  playermove (arrowKey);
	  
	  mapdisplay();
	  
	  cout << "Click arrow key to play\n";
	  cout << "------------------------\n";
	  cout << "click ESC to exit\n";
	  
	  arrowKey = getch();
	  
	  system ("cls");
	  
      // Ketika bertemu lawan   
      if (peta[koordinatY][koordinatX] == 2 )
	{
	      int choice;

	      cout << "\n\nApakah kau yakin ingin melawannya?\n";
	      cout << "1. Ya\n2. Tidak\n";
	      cout << "Pilihan : ";
	      cin >> choice;

		//system("clear");
	      if (choice == 1)
		{
			system ("cls");
		  int pilih, lagi;
		a:
		cout << "\n\nSelamat datang di game suit" << endl;
		cout << "Kamu pilih?\n\n";
		cout << "1. Gajah\n2. Semut\n3. Orang\n\n";
		cout << "Silahkan Pilih : ";
		cin >> pilih;
		cout << endl;
		int com;
		
		if (pilih == 1) {
			cout << "Kamu memilih gajah\n";
			srand(time(NULL));
			com = rand() % 10;
			if (com <= 3 && com >= 1)
			{
				cout << "Computer = Gajah\n\n";
				cout << "Seri\n"; 
			} else if (com <=6 && com >=4)
			{
				cout << "Computer = Orang\n\n";
				cout << "Kamu menang\n";
			} else 
			{
				cout << "Computer = Semut\n\n";
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
				cout << "Computer = Gajah\n\n";
				cout << "Kamu menang\n";
			} else 
			{
				cout << "Computer = Orang\n\n";
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
				cout << "Computer = Semut\n\n";
				cout << "Kamu menang\n";
			} else 
			{
				cout << "Computer = Gajah\n\n";
				cout << "Kamu kalah\n";
			} cout << endl;
		} else {
			cout << "Nomor yang anda input salah" << endl;
		}

		if (com <=3 && com >= 1)
		{
			// Ketika seri
			cout << "Pilih lagi??\n";
			cout << "1. lagi\n2. tidak\n";
			cout << "pilihan : ";
			cin >> lagi;
		b:
			if (lagi == 1){
				system ("cls");
				goto a;
		}
		  getch ();
		} else if (com <= 6 && com >= 4) 
		{
			//Ketika menang, jika memilih tidak maka akan keluar dari game
			int lanjut;
			peta[koordinatY][koordinatX] = 1; //menghilangkan musuh
			cout << "lanjut main??" << endl;
			cout << "1. lanjut\n2. tidak\n";
			cout << "pilihan : ";
			cin >> lanjut;
			if (lanjut == 1) 
			{
				system ("cls");
				goto main;
			} else if (lanjut == 2)
			{
				game++;
			}
		} else
		{
			//Ketika kalah
			int coba;
			cout << "Coba lagi ??\n";
			cout << "1. Ya\n2. Tidak\n";
			cout << "pilihan";
			cin >> coba;
			if (coba == 1)
			{
				system ("cls");
				goto a;
			}
		}
	}
    };
    if (arrowKey == ESC) {
    	system("cls");
    	char	 choice;
    	cout << "Are you sure want to exit?" << endl;
    	cout << "1. Yes \n2. No\n";
    	choice = getch();

    	if (choice == '1') {
			system ("cls");
			game++;
		} else if (choice == '2') {
			system("cls");
		}
	}
	}
	cout << "Terima kasih telah berjuang melawan musuh kami menanti kembali kedatangan anda" << endl;
  getch ();
  return 0;
};
