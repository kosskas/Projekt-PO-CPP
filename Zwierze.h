#ifndef _ZWIERZE_
#define _ZWIERZE_
#include "Organizm.h"
class Zwierze : public Organizm {
protected:
	int nextX;
	int nextY;
	int prevX;
	int prevY;
public:
	Zwierze(int s, int i);
	void akcja() override;
	virtual void nowaPozycja();
	void wycofajSie();
	virtual bool porownajGatunek(Organizm* drugi) const override;
	virtual void wykonajRuchNa(Organizm* kolizyjny);
	virtual ~Zwierze();
};
#endif // !_ZWIERZE_