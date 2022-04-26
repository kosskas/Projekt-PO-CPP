#ifndef _ORGANIZM_
#define _ORGANIZM_
#include "Swiat.h"
class Swiat;
class Organizm {
protected:
	int sila;
	int inicjatywa;
	int wiek;
	Swiat* swiat;
	int x;
	int y;
	bool zyje;
	virtual bool czyOdbilAtak(Organizm* atakujacy);
	virtual void rozmnazanie(Organizm* drugi);
	virtual Organizm* stworzNowy(int nowyY, int nowyX) = 0;
public:
	virtual void akcja() = 0;
	virtual void smierc();
	virtual char rysowanie() const = 0;
	virtual void kolizja(Organizm* atakujacy);
	virtual void nowaTura();
	virtual void SetSwiat(Swiat* S);
	virtual void SetSila(int wartosc);
	virtual void SetWiek(int wartosc);
	virtual bool czyZyje() const;
	virtual bool porownajGatunek(Organizm* drugi) const = 0;
	virtual int GetX() const;
	virtual int GetY() const;
	virtual int GetSila() const;
	virtual int GetInicjatywa() const;
	virtual int GetWiek() const;
	virtual ~Organizm();
};
bool porownajOrganizmy(const Organizm* pierwszy, const Organizm* drugi);
#endif // !_ORGANIZM_