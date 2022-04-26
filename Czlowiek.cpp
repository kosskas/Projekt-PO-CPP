#include "Czlowiek.h"
Czlowiek::Czlowiek(int posY, int posX)
	: Zwierze(CZLOWIEK) {
	x = posX;
	y = posY;
    czasTrwania = 0;
    czyAktywnaUmj = false;
    czasOczewiw = 0;
    czyMoze = true;
}
Czlowiek::Czlowiek(int posY, int posX, int wiek)
    : Czlowiek(posY, posX) {
    this->wiek = wiek;
}
void Czlowiek::nowaPozycja() {
    cout << "Czlowiek sila:  " << sila << endl;
    cout << UMJ_KLAWIATURA << " Uzycie zdolnosci specjalnej\n";
    cout << "Czlowiek wykonuje akcje: ";
    int dx = 0, dy = 0;
    _getch();
    switch (_getch()) {
        case GORA:
            cout << "GORA\n";
            dy = -1;
            break;
        case DOL:
            cout << "DOL\n";
            dy = 1;
            break;
        case PRAWO:
            cout << "PRAWO\n";
            dx = 1;
            break;
        case LEWO:
            cout << "LEWO\n";
            dx = -1;
            break;
        case UMJ_KLAWIATURA:
            if (czyMoze) {
                wypijMagicznyEliksir();
                cout << "Czlowiek wypil magiczny eliksir\n";
                nowaPozycja();
                return;
            }
            else {
                if (czyAktywnaUmj)
                    cout << "Zdolnosc jest aktywna\n";
                else
                    cout << "Pozostalo " << czasOczewiw << " rund do uzycia\n";
                nowaPozycja();
                return;
            }
            break;
        default:
               cout << "???\n";
            break;
    }
    if (swiat->sprawdzPoprawnoscWspolrzednych(x + dx, y + dy)) {
        nextX = x + dx;
        nextY = y + dy;
        prevX = x;
        prevY = y;
    }
}

void Czlowiek::wypijMagicznyEliksir() {
    sila = ELIKSIR_BONUS_SILA;
    czyAktywnaUmj = true;
    czasTrwania = CZAS_TRWANIA_UMIEJETNOSCI;
    czyMoze = false;
    czasOczewiw = CZAS_OCZEKIWANIA_NA_UMIEJETNOSC;
}
void Czlowiek::nowaTura() {
    if (czyAktywnaUmj) {
        czasTrwania--;
        sila--;
        if (czasTrwania == 0){
            cout << "Zdolnosc przestala dzialac\n";
            czyAktywnaUmj = false;
        }
    }
    else if (!czyMoze) {
        czasOczewiw--;
        if (czasOczewiw == 0) {
            cout << "Zdolnosc specjalna gotowa do uzycia\n";
            czyMoze = true;
        }
    }
    wiek++;
}
char Czlowiek::rysowanie() const {
	return SYMBOL_CZLOWIEK;
}

bool Czlowiek::porownajGatunek(Organizm* drugi) const {
    if (dynamic_cast<Czlowiek*>(drugi))
        return true;
    else
        return false;
}

Organizm* Czlowiek::stworzNowy(int nowyY, int nowyX) {
    return new Czlowiek(nowyY, nowyX);
}