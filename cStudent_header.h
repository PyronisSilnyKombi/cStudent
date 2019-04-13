#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include <fstream>
#include <sstream>
using namespace std;

class cStudent {
	//atrubuty
	string imie;
	string nazwisko;
	int rok_urodzenia;
	string plec;
	vector<pair<string, float>> oceny;
public:
	//metody
	cStudent();
	/*cStudent() :imie("Jan"), nazwisko("Kowalski"), rok_urodzenia(2000), plec("m"), oceny({}) {};*/
	cStudent(const string& im, const string& nazw, int ru = 0, const string& plec = "nn", const vector<pair<string, float>>& oc = {})
		:imie{ im }, nazwisko{ nazw }, rok_urodzenia{ ru }, plec{ plec }, oceny{ oc } {}  // make_pair<string,float>()
	/*cStudent(string _imie, string _nazwisko,int _rok_urodzenia, string _plec, vector<pair<string, float>> oceny);*/
	void pobierz();
	void pobierz_oceny(const vector<cStudent> &studenci);
	void wyswietl();
	void wyswietl_oceny();
	cStudent zwroc();
	float srednia();
	pair<string, float> najlepsza_ocena();
	pair<string, float> srednia_z_przedmiotu(string przedmiot);
	float srednia_z_przedmiotu(string przedmiot, int &divider);
	void usun_oceny(string przendiot);
	//zaprzyjaünione funkcje
	friend bool po_nazwisku(cStudent s1, cStudent s2);
	friend bool po_roku(cStudent s1, cStudent s2);
	friend bool po_imieniu(cStudent s1, cStudent s2);
	friend bool po_srednich(cStudent s1, cStudent s2);
	friend bool po_ocenach(pair<string, float> o1, pair<string, float> o2);
	friend cStudent parsuj(string osoba);
	friend string zapisz(vector<cStudent> studenci);
	friend vector<cStudent>::iterator szukanie_studenta(vector<cStudent>& studenci, string& nazwisko);
};

cStudent parsuj(string osoba);
string zapisz(vector<cStudent> studenci);
vector<cStudent>::iterator szukanie_studenta(vector<cStudent>& studenci, string& nazwisko);

bool po_nazwisku(cStudent s1, cStudent s2);
bool po_roku(cStudent s1, cStudent s2);
bool po_imieniu(cStudent s1, cStudent s2);
bool po_srednich(cStudent s1, cStudent s2);
bool po_ocenach(pair<string, float> o1, pair<string, float> o2);

int menu();
int menu_sort();
