#pragma once
#include "Roslina.h"
class BarszczSosnowskiego : public Roslina {
private:
	Organizm* sasiad[LICZBA_SASIADOW] = { NULL };
public:
	BarszczSosnowskiego(int posY, int posX);
	BarszczSosnowskiego(int posY, int posX, int wiek);
	char rysowanie() const override;
	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
	void GetSasiedzi();
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};