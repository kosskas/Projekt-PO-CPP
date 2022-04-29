#ifndef _ROSLINA_
#define _ROSLINA_
#include "Swiat.h"
class Roslina : public Organizm {
protected:
	int szansaSiewu;
public:
	Roslina(int s);
	virtual void akcja() override;
	virtual bool porownajGatunek(Organizm* drugi) const override;
	virtual ~Roslina();
};
#endif // !_ROSLINA_