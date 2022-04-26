#ifndef _WILK_
#define _WILK_
#include "Zwierze.h"
class Wilk : public Zwierze {
public:
	Wilk(int posY, int posX);
	Wilk(int posY, int posX, int wiek);
	char rysowanie() const override;
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};
#endif //!_WILK_
