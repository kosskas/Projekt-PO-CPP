#pragma once
#include "Zwierze.h"
class Owca : public Zwierze {
public:
	Owca(int posY, int posX);
	Owca(int posY, int posX, int wiek);
	char rysowanie() const override;
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};