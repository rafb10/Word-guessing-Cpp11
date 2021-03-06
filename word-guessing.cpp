﻿#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<utility>
#include<string>
#include <time.h>
#include <vector>


using namespace std;

int losuj_liczbe(int granica_gorna) {
	srand(time(NULL));
	int liczba = rand() % granica_gorna + 1;
	return liczba;
}



pair<string, string> kategoria_wyraz(string wiersz) {
	string temp_string;
	vector<string> wyrazy;
	int pozycja = wiersz.find(" ");
	while (pozycja != string::npos) {
		temp_string.assign(wiersz, 0, pozycja);
		wiersz.erase(0, pozycja + 1);
		wyrazy.push_back(temp_string);
		pozycja = wiersz.find(" ");
	}
	wyrazy.push_back(wiersz);
	int nr_wyrazu = losuj_liczbe(wyrazy.size() - 1);		
	return make_pair(wyrazy[0], wyrazy[nr_wyrazu]);

}


pair<string, string> losowanie(string nazwa_pliku)
{
	fstream plik;
	plik.open(nazwa_pliku, ios::in | ios::out);
	string wiersz;
	int ilosc_wierszy = 0;
	while (getline(plik, wiersz))
		ilosc_wierszy++;
	int nr_kategorii = losuj_liczbe(ilosc_wierszy);			
	plik.close();
	plik.open(nazwa_pliku, ios::in | ios::out);
	int i = 0;
	while (i < nr_kategorii) {
		getline(plik, wiersz);
		i++;
	}
	plik.close();
	pair<string, string> para(wiersz, wiersz);
	return kategoria_wyraz(wiersz);

}







// */
int main()
{

	pair<string, string> kat_i_wyraz = losowanie("Kategorie_slowa.txt");
	cout << "Wylosowales kategorie:  " << kat_i_wyraz.first << endl;
	char litera;
	string pelny_wyraz = kat_i_wyraz.second;
	int dlugosc = pelny_wyraz.size();
	string aktualny_wyraz(dlugosc, '-'); 
	cout << aktualny_wyraz << endl;
	cout << "Odgadnij litere (Wpisuj tylko DUZE LITERY)" << endl;
	cin>> litera;
	while (isalpha(litera)) {
		for (int i = 0; i < dlugosc; i++)
			if (pelny_wyraz[i]== litera)
				aktualny_wyraz[i] = litera;
		cout << aktualny_wyraz << endl;
		cout << "Odgadnij litere (Wpisuj tylko DUZE LITERY)" << endl;
		cin >> litera;
	}




	return 0;
}

