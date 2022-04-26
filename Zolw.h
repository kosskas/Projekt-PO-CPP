#ifndef _ZOLW_
#define _ZOLW_
#include "Zwierze.h"
class Zolw : public Zwierze {
public:
	Zolw(int posY, int posX);
	Zolw(int posY, int posX, int wiek);
	char rysowanie() const override;
	void nowaPozycja() override;
	void kolizja(Organizm* atakujacy) override;
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};
#endif // !_ZOLW_