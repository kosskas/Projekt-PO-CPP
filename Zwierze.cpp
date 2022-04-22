#include "Zwierze.h"

Zwierze::Zwierze(int s, int i){
	sila = s;
	inicjatywa = i;
	wiek = 0;
	zyje = true;
	prevY = y;
	prevX = x;
	nextY = y;
	nextX = x;
}
void Zwierze::akcja() {
	//cout << "Zwierze " << rysowanie() << " na pozycji "<<y<<" "<<x<<" wykonuje ruch \n";
	nowaPozycja();
	Organizm* kolizyjny = swiat->pobierzWspolrzedne(nextY, nextX);
	wykonunajRuchNa(kolizyjny);
	x = nextX;
	y = nextY;
}
void Zwierze::wykonunajRuchNa(Organizm* kolizyjny) {
	if (kolizyjny != NULL && kolizyjny != this) {
		if (porownajGatunek(kolizyjny)) {
			rozmnazanie(kolizyjny);
			nextX = x;
			nextY = y;
		}
		else {
			//this jest atakujacym
			//kolizyjny sie broni
			kolizyjny->kolizja(this);
		}
	}
}

void Zwierze::nowaPozycja() {
	int dx = 1;
	int dy = 1;
	dx = zasiegRuchuZwierze;
	dy = zasiegRuchuZwierze;
	if (swiat->sprawdzPoprawnoscWspolrzednych(y + dy, x + dx)) {
		nextX = x + dx;
		nextY = y + dy;
		prevX = x;
		prevY = y;
	}
}

void Zwierze::wycofajSie() {
	nextX = prevX;
	nextY = prevY;
}

bool Zwierze::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<Zwierze*>(drugi))
		return true;
	else
		return false;
}

Zwierze::~Zwierze() {
	swiat = NULL;
}