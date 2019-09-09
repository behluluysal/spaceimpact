#include "pch.h"
#include "Canavar.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
Canavar::Canavar()		//Canavar yapýcý metod
{
	srand(time(NULL));
	baslangic_X = 47;
	baslangic_Y = rand() % 10+2;
	for (int i = 0; i < 3; i++)
		x_Kordinatlar[i] = 47;
	y_Kordinatlar[0] = baslangic_Y;
	y_Kordinatlar[1] = baslangic_Y + 1;
	y_Kordinatlar[2] = baslangic_Y + 2;
	varMi = true;
}


Canavar::~Canavar()
{
}
void Canavar::Canavarolustur()	//Silinen canavarlarý tekrar oluþturmak için
{
	srand(time(NULL));
	baslangic_X = 47;
	baslangic_Y = rand() % 10+2;
	for (int i = 0; i < 3; i++)
		x_Kordinatlar[i] = 47;
	y_Kordinatlar[0] = baslangic_Y;
	y_Kordinatlar[1] = baslangic_Y + 1;
	y_Kordinatlar[2] = baslangic_Y + 2;
	varMi = true;
}

void Canavar::Canavarsil()	//Vurulan canavarlarý veya mapten çýkan canavarlarý silmek için
{
	srand(time(NULL));
	baslangic_X = NULL;
	baslangic_Y = NULL;
	for (int i = 0; i < 3; i++)
		x_Kordinatlar[i] = NULL;
	y_Kordinatlar[0] = NULL;
	y_Kordinatlar[1] = NULL;
	y_Kordinatlar[2] = NULL;
	varMi = false;
}

int Canavar::baslangicY_GET() { return baslangic_Y; }