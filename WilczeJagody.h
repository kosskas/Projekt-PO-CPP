#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina {
public:
	WilczeJagody(int posY, int posX);
	WilczeJagody(int posY, int posX, int wiek);
	char rysowanie() const override;
	void kolizja(Organizm* atakujacy) override;
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};