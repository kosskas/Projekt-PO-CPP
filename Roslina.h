#ifndef _ROSLINA_
#define _ROSLINA_
#include "Swiat.h"
class Roslina : public Organizm {
protected:
	int szansaSiewu;
public:
	Roslina(int s);
	virtual void akcja();
	virtual bool porownajGatunek(Organizm* drugi) const;
	virtual ~Roslina();
};
#endif // !_ROSLINA_