#pragma once
#include "Roslina.h"
class Mlecz : public Roslina {
public:
	Mlecz(int posY, int posX);
	Mlecz(int posY, int posX, int wiek);
	char rysowanie() const override;
	void akcja() override;
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};