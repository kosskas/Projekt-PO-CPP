#pragma once
#include "Zwierze.h"
class Lis : public Zwierze {
public:
	Lis(int posY, int posX);
	Lis(int posY, int posX, int wiek);
	char rysowanie() const override;
	void wykonunajRuchNa(Organizm* kolizyjny) override;
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};