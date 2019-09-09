#pragma once
class Ucak
{
private:

	int baslangic_X;
	int baslangic_Y;
	int mermi_Y[5];
	int mermi_X[5];	
public:
	Ucak();
	~Ucak();
	int x_Kordinatlar[5];
	int y_Kordinatlar[5];
	int ucakCiz(int mermisayisi);
	void yukariGit();
	void asagiGit();
	void atesEt();
	int baslangicX_GET();
	int baslangicY_GET();
	int *mermilerY_GET();
	int *mermilerX_GET();
};

