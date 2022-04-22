#include "WilczeJagody.h"
WilczeJagody::WilczeJagody(int posY, int posX)
	: Roslina(JAGODY) {
	x = posX;
	y = posY;
	szansaSiewu = SZANSA_JAGODY;
}
WilczeJagody::WilczeJagody(int posY, int posX, int wiek)
	: WilczeJagody(posY, posX) {
	this->wiek = wiek;
}
char WilczeJagody::rysowanie() const {
	return SYMBOL_JAGODY;
}
void WilczeJagody::kolizja(Organizm* atakujacy) {
	cout << "Zwierze " << atakujacy->rysowanie() << " zjadlo Wilcze jagody i umarlo\n";
	atakujacy->smierc();
	this->smierc();
}
bool WilczeJagody::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<WilczeJagody*>(drugi))
		return true;
	else
		return false;
}
Organizm* WilczeJagody::stworzNowy(int nowyY, int nowyX) {
	return new WilczeJagody(nowyY, nowyX);
}