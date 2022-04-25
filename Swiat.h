#pragma once
#include <iostream>
#include <time.h>
#include <list>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include "Organizm.h"

using namespace std;
class Organizm;

#define obliczSzanse(a) rand()%100 < a
#define sprawdzNapis(a, b) strcmp(a, b) == 0

//ogolne stale dla symulacji
#define zasiegRuchuZwierze rand() % 3 - 1
#define zasiegRuchuAntylopa rand() % 5 - 2

#define LICZBA_SASIADOW 8
#define WIEK_ROZMNAZANIA 2
#define SZANSZA_ANTYLOPY_NA_UCIECZKE 50
#define SZANSZA_ZOLW_NA_RUCH 25
#define PANCERZ_ZOLW 5
#define INICJATYWA_ROSLINA 0
#define GUARANA_BONUS 3
#define ILOSC_PROB_MLECZ 3

//zdolnosc specjalna dla czlowieka
#define ELIKSIR_BONUS_SILA 10
#define CZAS_TRWANIA_UMIEJETNOSCI 5
#define CZAS_OCZEKIWANIA_NA_UMIEJETNOSC 5

///Szansze na rozprzestrzenie rosliny w %
#define SZANSA_MLECZ 6
#define SZANSA_GUARANA 8
#define SZANSA_BARSZCZ 1
#define SZANSA_TRAWA 9
#define SZANSA_JAGODY 4

//sila i inicjatywa zwierzat
#define ANTYLOPA 4, 4
#define CZLOWIEK 5, 4
#define LIS 3, 7
#define OWCA 4, 4
#define WILK 9, 5
#define ZOLW 2, 1

//sila roslin
#define BARSZCZ 10
#define GUARANA 0
#define MLECZ 0
#define TRAWA 0
#define JAGODY 99

//symbole ASCII dla organizmow
#define SYMBOL_ANTYLOPA 'A'
#define SYMBOL_WILK 'W'
#define SYMBOL_CZLOWIEK 'C'
#define SYMBOL_OWCA 'O'
#define SYMBOL_LIS 'L'
#define SYMBOL_ZOLW 'Z'
#define SYMBOL_MLECZ '*'
#define SYMBOL_TRAWA '#'
#define SYMBOL_JAGODY '%'
#define SYMBOL_BARSZCZ '$'
#define SYMBOL_GUARANA '@'

class Swiat {
private:
	char** plansza;
	const int wymX;
	const int wymY;
	list<Organizm*> organizm;
	int tura;
	unsigned int seed;
	bool gra;
	void wyczyscMape();
	void naniesOrganizmyNaMape();
	void dodajOrganizmy(list<Organizm*> L);
	void zwolnijMiejsce();
public:
	Swiat(int N, int M, list<Organizm*> L);
	Swiat(int N, int M, list<Organizm*> L, int ziarno, int runda);
	void zapiszSwiat() const;
	void rysujSwiat();
	void rysujMape();
	int GetX() const;
	int GetY() const;
	void wykonajTure();
	void symuluj(int liczbaRund);
	Organizm* pobierzWspolrzedne(int y, int x);
	bool sprawdzPoprawnoscWspolrzednych(int y, int x);	
	void dodajOrganizm(Organizm* nowy);
	~Swiat();
};