#include "pch.h"
#include <iostream>
#include"Ucak.h"
#include"Canavar.h"
#include <conio.h>
#include <Windows.h>


using namespace std;

void gotoxy(int x, int y);
void klavyeOku(char tuslar[]);
void canavarCiz(int x, int y);
pair<int, int>mermiKontrol(Canavar *canavarlar[5], Ucak *ucak,int index,int skor,int mermisayisi);
bool oyunkontrol(Canavar *canavarlar[5], Ucak *ucak);
void haritaciz();

int main()
{
	pair<int, int>donut;
	int skor = 0;	//Skor
	int mermisayisi = 5;	//Mermi sayısı
	bool gameover = true;	//Oyunun devamını kontrol etmek için
	Ucak *ucak = new Ucak();
	Canavar *canavarlar[5];	//5 tane canavar oluşuyor oyun boyunca
	char tuslar[256];
	int sayac = -1, index = -1;	//Canavarları belli bir düzende göndermek için
	for (int i = 0; i < 5; i++)
		canavarlar[i] = NULL;
	do
	{
		system("cls");
		haritaciz();	//Harita çiziliyor
		gotoxy(0, 0);
		gotoxy(ucak->baslangicX_GET(), ucak->baslangicY_GET());
		mermisayisi=ucak->ucakCiz(mermisayisi);	//Uçak çiziliyor
		sayac++;
		if (sayac % 10 == 0 && index < 5)	//ilk 5 canavar burada oluşturuluyor
		{
			index++;
			if(canavarlar[index] == NULL)
			canavarlar[index] = new Canavar();

			if (canavarlar[index]->varMi == false)
				canavarlar[index]->Canavarolustur();
			if (sayac == 20)
				sayac = 1;
			if (index == 4)
				index = 0;
		}
		for (int i = 0; i < 5; i++)	// Canavarlar çiziliyor
		{
			if(canavarlar[i] !=NULL)
			if (canavarlar[i]->varMi != false)
			{
				canavarCiz(canavarlar[i]->baslangic_X--, canavarlar[i]->baslangicY_GET());
				for (int j = 0; j < 3; j++)
					canavarlar[i]->x_Kordinatlar[j]--;
			}
		}

		for (int i = 0; i < 5; i++)	//Mermiler çiziliyor
		{
			if (ucak->mermilerY_GET()[i] != -1)
			{
				gotoxy(ucak->mermilerX_GET()[i], ucak->mermilerY_GET()[i]);
				cout << ">";
			}
		}
		
		klavyeOku(tuslar);
		if (tuslar[38] != 0)
			ucak->yukariGit();
		else if (tuslar[40] != 0)
			ucak->asagiGit();
		else if (tuslar[32] != 0)
		{
			ucak->atesEt();
			mermisayisi--;
		}
		donut = mermiKontrol(canavarlar, ucak, index, skor, mermisayisi);	//Mermi canavar vurmuş mu kontrol ediliyor
		skor = donut.first;
		mermisayisi = donut.second;
		gotoxy(0, 16);
		cout << "Mermi sayisi: ";
		for (int i = 0; i < mermisayisi; i++)
			cout << "> ";
		cout << endl <<endl<< "Skorunuz: " << skor;
		gameover = oyunkontrol(canavarlar, ucak);	//Canavar uçağa vurmuş mu kontrol ediliyor
		Sleep(20);
	} while (gameover);

	cout << endl;
	system("pause");
	return 0;
}

void gotoxy(int x, int y)	//gotoxy metodu
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void klavyeOku(char tuslar[])	//Klavye tuş okuma metodu
{
	for (int x = 0; x < 256; x++)
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
}
void canavarCiz(int x, int y)	//canavar çizme metodu
{
	if (x > 4)
	{
		gotoxy(x, y);
		cout << "---\n";
		gotoxy(x, y + 1);
		cout << "|  |\n";
		gotoxy(x, y + 2);
		cout << "---";
	}
}
pair<int, int>mermiKontrol(Canavar *canavarlar[5], Ucak *ucak, int index,int skor,int mermisayisi)	//Mermi canavar vuruyor mu kontrol eden metod
{
	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			for (int k = 0; k < 3; k++) {
				if (canavarlar[i] != NULL)
				{
					if (canavarlar[i]->x_Kordinatlar[k] == ucak->mermilerX_GET()[j] && canavarlar[i]->y_Kordinatlar[k] == ucak->mermilerY_GET()[j])
					{
						canavarlar[i]->Canavarsil();
						ucak->mermilerY_GET()[j] = -1;
						ucak->mermilerX_GET()[j] = 4;
						index--;
						skor++;
						mermisayisi++;
					}
					if ((canavarlar[i]->x_Kordinatlar[k])+1 == ucak->mermilerX_GET()[j] && canavarlar[i]->y_Kordinatlar[k] == ucak->mermilerY_GET()[j])
					{
						canavarlar[i]->Canavarsil();
						ucak->mermilerY_GET()[j] = -1;
						ucak->mermilerX_GET()[j] = 4;
						index--;
						skor++;
						mermisayisi++;
					}
				}
				if (canavarlar[i] != NULL)
				{
					if (canavarlar[i]->x_Kordinatlar[k] == 0)
					{
						if (canavarlar[i]->varMi == true)
							skor--;
						canavarlar[i]->Canavarsil();
						index--;
						
					}
					if ((canavarlar[i]->x_Kordinatlar[k]) + 1 == 0)
					{
						if (canavarlar[i]->varMi == true)
							skor--;
						canavarlar[i]->Canavarsil();
						index--;
					}
				}
			}
		}
	}
	return pair<int, int> (skor,mermisayisi);
}

bool oyunkontrol(Canavar *canavarlar[5], Ucak *ucak)	//Uçak canavara çarpmış mı kontrol eden metod
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (canavarlar[i] != NULL)
				{
					if (canavarlar[i]->x_Kordinatlar[k] == ucak->x_Kordinatlar[j] && canavarlar[i]->y_Kordinatlar[k] == ucak->y_Kordinatlar[j])
					{
						gotoxy(0, 20);
						cout << "GAMEOVER";
						return false;
					}


					if ((canavarlar[i]->x_Kordinatlar[k]) +1 == ucak->x_Kordinatlar[j] && canavarlar[i]->y_Kordinatlar[k] == ucak->y_Kordinatlar[j])
					{
						gotoxy(0, 20);
						cout << "GAMEOVER";
						return false;
					}

				}
			}
		}
	}
}

void haritaciz() //harita çizme
{
	gotoxy(0, 0);
	cout << "--------------------------------------------------";
	for (int i = 0; i < 15; i++)
	{
		gotoxy(50, i);
		cout << "|";
	}
	gotoxy(0, 15);
	cout << "--------------------------------------------------";
}