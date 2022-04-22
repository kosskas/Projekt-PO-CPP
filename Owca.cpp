#include "Owca.h"
Owca::Owca(int posY, int posX)
	: Zwierze(OWCA) {
	x = posX;
	y = posY;
}
Owca::Owca(int posY, int posX, int wiek)
	: Owca(posY, posX) {
	this->wiek = wiek;
}
char Owca::rysowanie() const {
	return SYMBOL_OWCA;
}
bool Owca::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<Owca*>(drugi))
		return true;
	else
		return false;
}
Organizm* Owca::stworzNowy(int nowyY, int nowyX) {
	return new Owca(nowyY, nowyX);
}