#ifndef _ANTYLOPA_
#define _ANTYLOPA_
#include "Zwierze.h"
class Antylopa : public Zwierze {
public:
	Antylopa(int posY, int posX);
	Antylopa(int posY, int posX, int wiek);
	char rysowanie() const override;
	void nowaPozycja() override;
	void kolizja(Organizm* atakujacy) override;
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};
#endif // !_ANTYLOPA_
