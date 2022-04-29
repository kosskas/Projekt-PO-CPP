#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"

#define MAX_CMD_DL 10
#define WYM_Y 20
#define WYM_X 20
#define L_RUND 300

void dodaj(list<Organizm*>& A);
Swiat* wczytaj();

int main() {
    list<Organizm*> L;
    Swiat* S = NULL;
	char komenda[MAX_CMD_DL];
	cout << "[Mateusz Stencel, s188676 Informatyka]" << endl;
	cout << "Ruch :\030\031\032\033" << endl;
    cout << "wczytaj => [stan]" << endl;
    cin >> komenda;
    if (sprawdzNapis(komenda, "[stan]")) {
		S = wczytaj();
    }
	else {
		dodaj(L);
		S = new Swiat(WYM_Y, WYM_X, L);
	}
	if (S)
		S->symuluj(L_RUND);
    delete S;
    return 0;
}

void dodaj(list<Organizm*>& A) {
	A.push_back(new Owca(0, 0));
	A.push_back(new Owca(1, 0));
	A.push_back(new Owca(0, 1));

	A.push_back(new BarszczSosnowskiego(4, 0));
	A.push_back(new BarszczSosnowskiego(0, 4));
	A.push_back(new BarszczSosnowskiego(3, 4));


	A.push_back(new Lis(5, 4));
	A.push_back(new Lis(4, 3));

	A.push_back(new Zolw(7, 7));
	A.push_back(new Zolw(10, 9));

	A.push_back(new Owca(7, 8));

	A.push_back(new Trawa(7, 2));

	A.push_back(new Mlecz(1, 10));

	A.push_back(new Guarana(2, 7));

	A.push_back(new Antylopa(8, 3));
	A.push_back(new Antylopa(6, 7));
	A.push_back(new Antylopa(8, 7));
	A.push_back(new Antylopa(2, 2));

	A.push_back(new WilczeJagody(5, 7));

	A.push_back(new Wilk(3, 6));
	A.push_back(new Wilk(3, 5));

	A.push_back(new Czlowiek(10, 10));
}

Swiat* wczytaj(){
	char komenda[10];
	int mapX = 0, mapY = 0, runda = 0 , wiek = 0, y = 0, x = 0;
	unsigned int ziarno = 0;
	list<Organizm*> N;
	do {
		cin >> komenda;
		if (sprawdzNapis(komenda, "MAPA")) {
			cin >> mapY >> mapX;
		}
		else if (sprawdzNapis(komenda, "SEED")) {
			cin >> ziarno;
		}
		else if (sprawdzNapis(komenda, "TURA")) {
			cin >> runda;
		}
		else if (sprawdzNapis(komenda, "[org]")) {
			do {
				cin >> komenda;
				if (sprawdzNapis(komenda, "W")) {
					//wilk
					cin >> y >> x >> wiek;
					N.push_back(new Wilk(y, x, wiek));
				}
				else if (sprawdzNapis(komenda, "O")) {
					//owca
					cin >> y >> x >> wiek;
					N.push_back(new Owca(y, x, wiek));
				}
				else if (sprawdzNapis(komenda, "L")) {
					//lis
					cin >> y >> x >> wiek;
					N.push_back(new Lis(y, x, wiek));
				}
				else if (sprawdzNapis(komenda, "Z")) {
					//zolw
					cin >> y >> x >> wiek;
					N.push_back(new Zolw(y, x, wiek));
				}
				else if (sprawdzNapis(komenda, "A")) {
					//antylopa
					cin >> y >> x >> wiek;
					N.push_back(new Antylopa(y, x, wiek));
				}
				else if (sprawdzNapis(komenda, "C")) {
					//czlowiek
					cin >> y >> x >> wiek;
					N.push_back(new Czlowiek(y, x, wiek));
				}
				else if (sprawdzNapis(komenda, "#")) {
					//Trawa
					cin >> y >> x >> wiek;
					N.push_back(new Trawa(y, x, wiek));
				}
				else if (sprawdzNapis(komenda, "*")) {
					//mlecz
					cin >> y >> x >> wiek;
					N.push_back(new Mlecz(y, x, wiek));
				}
				else if (sprawdzNapis(komenda, "@")) {
					//guarana
					cin >> y >> x >> wiek;
					N.push_back(new Guarana(y, x, wiek));
					}
				else if (sprawdzNapis(komenda, "%")) {
					//wjagody
					cin >> y >> x >> wiek;
					N.push_back(new WilczeJagody(y, x, wiek));
				}
				else if (sprawdzNapis(komenda, "$")) {
					//barszcz
					cin >> y >> x >> wiek;
					N.push_back(new BarszczSosnowskiego(y, x, wiek));
				}				
			} while (!sprawdzNapis(komenda, "[org]"));
		}
	} while (!sprawdzNapis(komenda, "[stan]"));
	if (mapY && mapX && !N.empty())
		return new Swiat(mapY, mapX, N, ziarno, runda);
	else
		return NULL;
}