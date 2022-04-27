#include "Organizm.h"

bool Organizm::czyOdbilAtak(Organizm* atakujacy){
	if (sila < atakujacy->GetSila())
		return false;
	else
		return true;
}

void Organizm::rozmnazanie(Organizm* drugi) {
	if (wiek > WIEK_ROZMNAZANIA && drugi->GetWiek() > WIEK_ROZMNAZANIA) {
		for (int dy = -1; dy <= 1; dy++) {
			for (int dx = -1; dx <= 1; dx++) {
				Organizm* dziecko = swiat->pobierzWspolrzedne(y + dy, x + dx);
				if (dziecko == NULL && swiat->sprawdzPoprawnoscWspolrzednych(y + dy, x + dx)) {
					dziecko = stworzNowy(y + dy, x + dx);
					if (dziecko != NULL) {
						swiat->dodajOrganizm(dziecko);
					}
					break;
				}
			}
		}
	}
}

void Organizm::smierc() {
	zyje = false;
}

void Organizm::nowaTura() {
	wiek++;
}

void Organizm::kolizja(Organizm* atakujacy) {
	if (this->czyOdbilAtak(atakujacy)) {
		cout << this->rysowanie() << " zabil " << atakujacy->rysowanie() << endl;
		atakujacy->smierc();
	}
	else {
		cout << atakujacy->rysowanie() << " zabil " << this->rysowanie() << endl;
		this->smierc();
	}
}


void Organizm::SetSwiat(Swiat* S) {
	swiat = S;
}

void Organizm::SetSila(int wartosc) {
	sila = wartosc;
}

void Organizm::SetWiek(int wartosc) {
	wiek = wartosc;
}

bool Organizm::czyZyje() const {
	return zyje;
}

int Organizm::GetX() const {
	return x;
}

int Organizm::GetY() const {
	return y;
}

int Organizm::GetSila() const {
	return sila;
}

int Organizm::GetInicjatywa() const {
	return inicjatywa;
}

int Organizm::GetWiek() const {
	return wiek;
}

bool porownajOrganizmy(const Organizm* pierwszy, const Organizm* drugi) {
	if (pierwszy->GetInicjatywa() > drugi->GetInicjatywa())
		return true;
	else if (pierwszy->GetInicjatywa() == drugi->GetInicjatywa()) {
		return pierwszy->GetWiek() > drugi->GetWiek();
	}
	else
		return false;
}
Organizm::~Organizm() {}