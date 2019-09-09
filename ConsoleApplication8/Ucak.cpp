
#include "pch.h"
#include "Ucak.h"
#include<iostream>
using namespace std;
Ucak::Ucak()		//Uçak yapýcý metod
{
	for (int i = 0; i < 5; i++)
	{
		y_Kordinatlar[i] = i+1;//12345
		mermi_Y[i] = -1;
		mermi_X[i] = 4;
	}
	x_Kordinatlar[0] = 2;
	x_Kordinatlar[1] = 3;
	x_Kordinatlar[2] = 4;
	x_Kordinatlar[3] = 3;
	x_Kordinatlar[4] = 2;
	baslangic_X = 0;
	baslangic_Y = 1;

}


Ucak::~Ucak()
{
}

int Ucak::ucakCiz(int mermisayisi)	//Uçak çizme metodu
{
	cout << " /\\" << endl << "<=>\\" << endl << "<>*}>" << endl << "<=>/" << endl << " \\/";
	for (int i = 0; i < 5; i++)
	{
		if (mermi_Y[i] != -1)
		{
			if (mermi_X[i] < 50)
				mermi_X[i]++;
			if (mermi_X[i] == 50 || mermi_X[i] == 49)	//Mermilerin kontrolleri de burada yapýlýyor
			{
				mermi_Y[i] = -1;
				mermi_X[i] = 4;
				mermisayisi++;
			}
		}
	}
	return mermisayisi;
}

void Ucak::yukariGit()	//Uçaðý yukarý hareket ettirme
{
	if (baslangic_Y > 1)
	{
		baslangic_Y--;
		for (int i = 0; i < 5; i++)
			y_Kordinatlar[i]--;
	}

}
void Ucak::asagiGit()		//Uçaðý aþaðý hareket ettirme
{
	if (baslangic_Y < 10)
	{
		baslangic_Y++;
		for (int i = 0; i < 5; i++)
			y_Kordinatlar[i]++;
	}

}
void Ucak::atesEt()	//Ateþ etme metodu
{
	for (int i = 0; i < 5; i++)
	{
		if (mermi_Y[i] == -1) {
			mermi_Y[i] = baslangic_Y + 2;
			break;
		}
	}
}
int Ucak::baslangicX_GET() { return baslangic_X; }
int Ucak::baslangicY_GET() { return baslangic_Y; }
int *Ucak::mermilerY_GET() { return mermi_Y; }
int *Ucak::mermilerX_GET() { return mermi_X; }