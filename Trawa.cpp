#include "Trawa.h"
Trawa::Trawa(int posY, int posX)
	: Roslina(TRAWA) {
	x = posX;
	y = posY;
	szansaSiewu = SZANSA_TRAWA;
}
Trawa::Trawa(int posY, int posX, int wiek)
	: Trawa(posY, posX) {
	this->wiek = wiek;
}
char Trawa::rysowanie() const {
	return SYMBOL_TRAWA;
}
bool Trawa::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<Trawa*>(drugi))
		return true;
	else
		return false;
}
Organizm* Trawa::stworzNowy(int nowyY, int nowyX) {
	return new Trawa(nowyY, nowyX);
}