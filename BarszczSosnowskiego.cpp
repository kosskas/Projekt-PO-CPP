#include "BarszczSosnowskiego.h"
BarszczSosnowskiego::BarszczSosnowskiego(int posY, int posX)
	: Roslina(BARSZCZ) {
	x = posX;
	y = posY;
	szansaSiewu = SZANSA_BARSZCZ;
}
BarszczSosnowskiego::BarszczSosnowskiego(int posY, int posX, int wiek)
	: BarszczSosnowskiego(posY, posX) {
	this->wiek = wiek;
}
char BarszczSosnowskiego::rysowanie() const {
	return SYMBOL_BARSZCZ;
}
void BarszczSosnowskiego::akcja() {
	GetSasiedzi();
	for (int i = 0; i < LICZBA_SASIADOW; i++) {
		if (sasiad[i] && !Roslina::porownajGatunek(sasiad[i])){
			cout <<sasiad[i]->rysowanie() << " ginie od barszczu\n";
			sasiad[i]->smierc();
		}
	}
	if(wiek > WIEK_ROZMNAZANIA)
		Roslina::akcja();
}
void BarszczSosnowskiego::kolizja(Organizm* atakujacy) {
	cout << atakujacy->rysowanie() << " zjadlo Barszcz Sosnowskiego i umarlo\n";
	atakujacy->smierc();
	this->smierc();
}
bool BarszczSosnowskiego::porownajGatunek(Organizm* drugi) const {
	if (dynamic_cast<BarszczSosnowskiego*>(drugi))
		return true;
	else
		return false;
}
Organizm* BarszczSosnowskiego::stworzNowy(int nowyY, int nowyX) {
	return new BarszczSosnowskiego(nowyY, nowyX);
}
void BarszczSosnowskiego::GetSasiedzi() {
	sasiad[0] = swiat->pobierzWspolrzedne(y - 1, x);
	sasiad[1] = swiat->pobierzWspolrzedne(y - 1, x - 1);
	sasiad[2] = swiat->pobierzWspolrzedne(y + 1, x - 1);
	sasiad[3] = swiat->pobierzWspolrzedne(y - 1, x);
	sasiad[4] = swiat->pobierzWspolrzedne(y + 1, x);
	sasiad[5] = swiat->pobierzWspolrzedne(y - 1, x + 1);
	sasiad[6] = swiat->pobierzWspolrzedne(y, x + 1);
	sasiad[7] = swiat->pobierzWspolrzedne(y + 1, x + 1);
}