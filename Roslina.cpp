#include "Roslina.h"
Roslina::Roslina(int s){
	sila = s;
	inicjatywa = INICJATYWA_ROSLINA;
	zyje = true;
	wiek = 0;
}
void Roslina::akcja(){
	if (obliczSzanse(szansaSiewu)) {
		rozmnazanie(this);
	}
}

bool Roslina::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<Roslina*>(drugi))
		return true;
	else
		return false;
}

Roslina::~Roslina(){
	swiat = NULL;
}