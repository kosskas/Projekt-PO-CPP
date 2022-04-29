#ifndef _LIS_
#define _LIS_
#include "Zwierze.h"
class Lis : public Zwierze {
public:
	Lis(int posY, int posX);
	Lis(int posY, int posX, int wiek);
	char rysowanie() const override;
	void wykonajRuchNa(Organizm* kolizyjny) override;
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};
#endif // !_LIS_