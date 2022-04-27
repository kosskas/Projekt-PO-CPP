#include "Antylopa.h"
Antylopa::Antylopa(int posY, int posX)
	: Zwierze(ANTYLOPA) {
	x = posX;
	y = posY;
	prevX = x;
	prevY = y;
}
Antylopa::Antylopa(int posY, int posX, int wiek)
	: Antylopa(posY, posX) {
	this->wiek = wiek;
}
char Antylopa::rysowanie() const {
	return SYMBOL_ANTYLOPA;
}
void Antylopa::nowaPozycja() {
	int dx = 1;
	int dy = 1;
	dx = zasiegRuchuAntylopa;
	dy = zasiegRuchuAntylopa;
	if (swiat->sprawdzPoprawnoscWspolrzednych(y+ dy, x + dx)) {
		nextX = x + dx;
		nextY = y + dy;
		prevX = x;
		prevY = y;
	}
}
void Antylopa::kolizja(Organizm* atakujacy) {
	if (obliczSzanse(SZANSZA_ANTYLOPY_NA_UCIECZKE)) {
		Zwierze::nowaPozycja();
		Organizm* kolizyjny = swiat->pobierzWspolrzedne(nextY, nextX);
		if (kolizyjny != NULL && kolizyjny != this)
			Zwierze::kolizja(atakujacy);
		else {
			x = nextX;
			y = nextY;
		}
	}
	else {
		Zwierze::kolizja(atakujacy);
	}
}
bool Antylopa::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<Antylopa*>(drugi))
		return true;
	else
		return false;
}

Organizm* Antylopa::stworzNowy(int nowyY, int nowyX) {
	return new Antylopa(nowyY, nowyX);
}
