#pragma once
#include "Organizm.h"
class Zwierze : public Organizm {
protected:
	int nextX;
	int nextY;
	int prevX;
	int prevY;
public:
	Zwierze(int s, int i);
	void akcja();
	virtual void nowaPozycja();
	void wycofajSie();
	virtual bool porownajGatunek(Organizm* drugi) const;
	virtual void wykonunajRuchNa(Organizm* kolizyjny);
	virtual ~Zwierze();
};