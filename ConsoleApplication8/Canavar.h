#pragma once
class Canavar
{
private:
	int baslangic_Y;
public:
	int baslangic_X;
	int baslangicY_GET();
	int x_Kordinatlar[3];
	int y_Kordinatlar[3];
	void Canavarolustur();
	void Canavarsil();
	bool varMi;
	Canavar();
	~Canavar();
};

