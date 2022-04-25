#include "Swiat.h"

Swiat::Swiat(int Y, int X, list<Organizm*> L)
	: wymY(Y), wymX(Y), plansza(new char* [Y]) {
	for (int y = 0; y < Y; y++)
		plansza[y] = new char[X];
	dodajOrganizmy(L);
	seed = (unsigned int)time(NULL);
	srand(seed);
	tura = 0;
	gra = true;
}
Swiat::Swiat(int N, int M, list<Organizm*> L, int ziarno, int runda)
	: Swiat(N, M, L) {
	this->tura = runda;
	this->seed = ziarno;
	srand(seed);
}

void Swiat::rysujSwiat() {
	wyczyscMape();
	naniesOrganizmyNaMape();
	rysujMape();
}

void Swiat::dodajOrganizmy(list<Organizm*> L) {
	organizm = L;
	for (Organizm* N : L)
		N->SetSwiat(this);
}

void Swiat::naniesOrganizmyNaMape() {
	for (Organizm* N : organizm) {
		if(N->czyZyje())
			plansza[N->GetY()][N->GetX()] = N->rysowanie();
	}
}

void Swiat::wyczyscMape() {
	for (int y = 0; y < wymY; y++) {
		for (int x = 0; x < wymX; x++) {
			plansza[y][x] = '.';
		}
	}
}

void Swiat::rysujMape() {
	cout << "   ";
	int pom = -1;
	for (int x = 0; x < wymX; x++) {
		if (x % 10 == 0)
			pom++;
		cout << pom<<" ";
	}
	cout << endl<< "   ";
	for (int x = 0; x < wymX; x++) {
		cout << x % 10<<" ";
	}
	cout << endl;
	pom = -1;
	for (int y = 0; y < wymY; y++) {
		if (y % 10 == 0)
			pom++;
		cout << pom << y % 10<<" ";
		for (int x = 0; x < wymX; x++) {
			cout << plansza[y][x] << " ";
		}
		cout << endl;
	}
}

void Swiat::symuluj(int liczbaRund) {	
	for (int i = tura; i < liczbaRund && gra; i++) {	
		cout << "Nacisnij dowolny przycisk aby kontynuowaæ lub 'z' zeby zapisac\n";
		if (_getch() == 'z'){
			zapiszSwiat();
			gra = false;
			_getch();
			break;
		}
		system("cls");
		rysujSwiat();
		cout << "\tTura " << i << endl;
		wykonajTure();
		rysujSwiat();
		
	}
	cout << endl;
}

void Swiat::zapiszSwiat() const{
	cout << "[stan]"<< endl;
	cout << "MAPA " << wymY << " " << wymX << endl;
	cout << "SEED " << seed << endl;
	cout << "TURA "<<tura<< endl;
	cout << "[org]" << endl;
	for (Organizm* N : organizm) {
		cout << N->rysowanie() <<" "<< N->GetY() << " " << N->GetX() << " " << N->GetWiek() <<endl;
	}
	cout << "[org]" << endl;
	cout << "[stan]" << endl;
}

int Swiat::GetX() const{
	return wymX;
}

int Swiat::GetY() const{
	return wymY;
}

bool Swiat::sprawdzPoprawnoscWspolrzednych(int y, int x) {
	if (x < wymX && x >= 0 && y < wymY && y >= 0) {
		return true;
	}
	else {
		return false;
	}
}

void Swiat::wykonajTure() {
	tura++;
	zwolnijMiejsce();
	organizm.sort(porownajOrganizmy);
	for (Organizm* N : organizm) {
		N->nowaTura();
		if(N->GetWiek() > 1)
			N->akcja();
	}
}

Organizm* Swiat::pobierzWspolrzedne(int y, int x) {
	for (Organizm* N : organizm) {
		if (N->GetX() == x && N->GetY() == y && N->czyZyje())
			return N;
	}
	return NULL;
}

void Swiat::dodajOrganizm(Organizm* nowy) {
	nowy->SetSwiat(this);
	organizm.push_back(nowy);
}

void Swiat::zwolnijMiejsce() {
	organizm.remove_if([](Organizm* N) {
		return N->czyZyje() == false;
		});
}

Swiat::~Swiat() {
	for (int y = 0; y < wymY; y++) {
		delete[] plansza[y];
	}
	delete[] plansza;
	plansza = NULL;
	for (Organizm* N : organizm) {
		delete N;
	}
	organizm.clear();
}