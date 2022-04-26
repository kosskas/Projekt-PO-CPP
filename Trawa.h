#ifndef _TRAWA_
#define _TRAWA_
#include "Roslina.h"
class Trawa : public Roslina {
public:
	Trawa(int posY, int posX);
	Trawa(int posY, int posX, int wiek);
	char rysowanie() const override;
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};
#endif // !_TRAWA_
