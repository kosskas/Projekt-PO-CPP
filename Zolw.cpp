#include "Zolw.h"
Zolw::Zolw(int posY, int posX)
	: Zwierze(ZOLW) {
	x = posX;
	y = posY;
	prevX = x;
	prevY = y;
}
Zolw::Zolw(int posY, int posX, int wiek)
	: Zolw(posY, posX) {
	this->wiek = wiek;
}
char Zolw::rysowanie() const {
	return SYMBOL_ZOLW;
}
void Zolw::nowaPozycja() {
	if (obliczSzanse(SZANSZA_ZOLW_NA_RUCH)) {
		Zwierze::nowaPozycja();
	}
	else {
		nextX = x;
		nextY = y;
	}
}
void Zolw::kolizja(Organizm* atakujacy) {
	if (atakujacy->GetSila() < PANCERZ_ZOLW) {
		dynamic_cast<Zwierze*>(atakujacy)->wycofajSie();
		cout << this->rysowanie() << " ODBIL ATAK";
		cout << "\n\t\tZwierze " << atakujacy->rysowanie() << " wycofuje sie\n";
	}
	else {
		this->smierc();
	}
}
bool Zolw::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<Zolw*>(drugi))
		return true;
	else
		return false;
}
Organizm* Zolw::stworzNowy(int nowyY, int nowyX) {
	return new Zolw(nowyY, nowyX);
}