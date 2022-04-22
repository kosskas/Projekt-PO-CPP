#include "Wilk.h"
Wilk::Wilk(int posY, int posX)
	: Zwierze(WILK) {
	x = posX;
	y = posY;
	prevX = x;
	prevY = y;
}
Wilk::Wilk(int posY, int posX, int wiek)
	: Wilk(posY, posX) {
	this->wiek = wiek;
}
char Wilk::rysowanie() const {
	return SYMBOL_WILK;
}
bool Wilk::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<Wilk*>(drugi))
		return true;
	else
		return false;
}
Organizm* Wilk::stworzNowy(int nowyY, int nowyX) {
	return new Wilk(nowyY, nowyX);
}