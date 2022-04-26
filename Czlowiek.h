#ifndef _CZLOWIEK_
#define _CZLOWIEK_
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int czasTrwania;
	int czasOczewiw;
	bool czyAktywnaUmj;
	bool czyMoze;
public:
	Czlowiek(int posY, int posX);
	Czlowiek(int posY, int posX, int wiek);
	void wypijMagicznyEliksir();
	void nowaPozycja() override;
	void nowaTura() override;
	char rysowanie() const override;
	bool porownajGatunek(Organizm* drugi) const override;
	Organizm* stworzNowy(int nowyY, int nowyX) override;
};
#endif // !_CZLOWIEK_