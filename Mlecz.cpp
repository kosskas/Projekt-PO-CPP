#include "Mlecz.h"
Mlecz::Mlecz(int posY, int posX)
	: Roslina(MLECZ) {
	x = posX;
	y = posY;
	szansaSiewu = SZANSA_MLECZ;
}
Mlecz::Mlecz(int posY, int posX, int wiek)
	: Mlecz(posY, posX) {
	this->wiek = wiek;
}
char Mlecz::rysowanie() const {
	return SYMBOL_MLECZ;
}
void Mlecz::akcja() {
	for (int i = 0; i < ILOSC_PROB_MLECZ; i++)
		Roslina::akcja();
}
bool Mlecz::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<Organizm*>(drugi))
		return true;
	else
		return false;
}
Organizm* Mlecz::stworzNowy(int nowyY, int nowyX) {
	return new Mlecz(nowyY, nowyX);
}