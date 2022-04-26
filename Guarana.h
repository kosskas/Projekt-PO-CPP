#ifndef _GUARANA_
#define _GUARANA_
#include "Roslina.h"
class Guarana : public Roslina {
public:
	Guarana(int posY, int posX);
	Guarana(int posY, int posX, int wiek);
	char rysowanie() const override;
	void kolizja(Organizm* atakujacy) override;
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};
#endif // !_GUARANA_