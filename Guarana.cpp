#include "Guarana.h"
Guarana::Guarana(int posY, int posX)
	: Roslina(GUARANA) {
	x = posX;
	y = posY;
	szansaSiewu = SZANSA_GUARANA;
}
Guarana::Guarana(int posY, int posX, int wiek)
	: Guarana(posY, posX) {
	this->wiek = wiek;
}
char Guarana::rysowanie() const {
	return SYMBOL_GUARANA;
}
void Guarana::kolizja(Organizm* atakujacy) {
	cout << "\nRoslina " << this->rysowanie() << " zostala zjedzona i zwierza sile: "
		<< atakujacy->rysowanie() << " z " << atakujacy->GetSila();
	atakujacy->SetSila(atakujacy->GetSila() + GUARANA_BONUS);
	cout << " do " << atakujacy->GetSila() << endl;
	this->smierc();
}
bool Guarana::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<Guarana*>(drugi))
		return true;
	else
		return false;
}
Organizm* Guarana::stworzNowy(int nowyY, int nowyX) {
	return new Guarana(nowyY, nowyX);
}