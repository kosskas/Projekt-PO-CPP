#pragma once
#include "Zwierze.h"
#define GORA 72
#define DOL 80
#define PRAWO 77
#define LEWO 75
#define UMJ 'u'

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

