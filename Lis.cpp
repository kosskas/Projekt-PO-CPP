#include "Lis.h"
Lis::Lis(int posY, int posX)
	: Zwierze(LIS) {
	x = posX;
	y = posY;
	prevX = x;
	prevY = y;
}
Lis::Lis(int posY, int posX, int wiek)
	: Lis(posY, posX) {
	this->wiek = wiek;
}
char Lis::rysowanie() const {
	return SYMBOL_LIS;
}

void Lis::wykonunajRuchNa(Organizm* kolizyjny) {
	if (kolizyjny != NULL && kolizyjny != this && kolizyjny->GetSila() > sila) {
		cout << "\t\tLis nie wykonuje ruchu na " << kolizyjny->rysowanie() << endl;
		nextX = x;
		nextY = y;
	}
	else
		Zwierze::wykonunajRuchNa(kolizyjny);
}
bool Lis::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<Lis*>(drugi))
		return true;
	else
		return false;
}
Organizm* Lis::stworzNowy(int nowyY, int nowyX) {
	return new Lis(nowyY, nowyX);
}
