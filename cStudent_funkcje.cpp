#include "cStudent_header.h"


int menu() {
	int liczba;
	cout << "MENU : " << endl;
	cout << "1 - Wprowadzanie danych studentow" << endl;
	cout << "2 - Wprowadzanie ocen studentow" << endl;
	cout << "3 - Sortowanie studentow" << endl;
	cout << "4 - Osoba z najlepsza srednia" << endl;
	cout << "5 - Sukcesy studentow" << endl;
	cout << "6 - Obliczanie srednich z przedmiotow" << endl;
	cout << "7 - Sortowanie studentow wedlug ocen z danego przedmiotu" << endl;
	cout << "8 - Wczytywanie studentow z pliku" << endl;
	cout << "9 - Zapis do pliku" << endl;
	cout << "10 - Usuwanie studenta" << endl;
	cout << "11 - Usuwanie przedmiotu" << endl;
	cout << "Podaj liczbe : "; cin >> liczba;
	system("cls");
	return liczba;
}

int menu_sort() {
	int liczba;
	cout << "MENU : " << endl;
	cout << "1 - Sortowanie studentow wedlug nazwiska" << endl;
	cout << "2 - Sortowanie studentow wedlug imienia" << endl;
	cout << "3 - Sortowanie studentow wedlug daty urodzenia" << endl;
	cout << "Podaj liczbe : "; cin >> liczba;
	system("cls");
	return liczba;
}

cStudent::cStudent() {
	imie = "Jan";
	nazwisko = "Kowalski";
	rok_urodzenia = 2000;
	plec = "m";
	oceny = {};
}

//cStudent::cStudent():imie("Jan"), nazwisko("Kowalski"), rok_urodzenia(2000), plec("m"), oceny({}) {
//
//}

//cStudent::cStudent(string _imie, string _nazwisko, int _rok_urodzenia, string _plec, vector<pair<string, float>> _oceny) {
//	nazwisko = _nazwisko;
//	imie = _imie;
//	rok_urodzenia = _rok_urodzenia;
//	plec = _plec;
//	oceny = _oceny;
//}

void cStudent::pobierz() {

	cout << "Dodawanie studenta" << endl;
	cout << "Podaj imie : ";
	cin >> imie;
	cout << "Podaj nazwisko : ";
	cin >> nazwisko;
	cout << "Podaj rok urodzenia : ";
	cin >> rok_urodzenia;
	cout << "Podaj plec (m/k) : ";
	cin >> plec;
	system("cls");
}

void cStudent::pobierz_oceny(const vector<cStudent>& studenci) {

	int n;
	cout << "Ile ocen chcesz wprowadzic : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<string, float> ocena;
		cout << "Podaj nazwe przemiotu : ";
		cin.ignore();
		getline(cin, ocena.first);
		if (ocena.first == " ") break;
		cout << "Podaj ocene : ";
		cin >> ocena.second;
		oceny.push_back(ocena);
	}
	system("cls");
}

void cStudent::wyswietl() {
	cout << "Imie : " << imie << endl;
	cout << "Nazwisko : " << nazwisko << endl;
	cout << "Rok urodzenia : " << rok_urodzenia << endl;
}

void cStudent::wyswietl_oceny() {
	for (auto& el : oceny) {
		cout << el.first << endl;
		cout << el.second << endl;
	}
}

cStudent cStudent::zwroc() {
	cStudent s1;
	s1.pobierz();
	return s1;
}

float cStudent::srednia() {
	float suma = 0;
	for (auto& el : oceny) {
		suma += el.second;
	}
	return suma / oceny.size();
}

pair<string, float> cStudent::srednia_z_przedmiotu(string przedmiot) {
	pair<string, float> s1;
	float suma = 0;
	int divider = 0;
	for (int j = 0; j < oceny.size(); j++) {
		if (przedmiot == oceny[j].first) {
			suma += oceny[j].second;
			divider++;
		}
	}
	s1.first = nazwisko;
	s1.second = suma / divider;
	return s1;
}


float cStudent::srednia_z_przedmiotu(string przedmiot, int &divider) {
	float suma = 0;
	for (int j = 0; j < oceny.size(); j++) {
		if (przedmiot == oceny[j].first) {
			suma += oceny[j].second;
			divider++;
		}
	}
	return suma;
}

void cStudent::usun_oceny(string przedmiot) {
	for (int j = 0; j < oceny.size(); j++) {
		if (przedmiot == oceny[j].first) {
			oceny.erase(oceny.begin() + j);
			usun_oceny(przedmiot);
		}
	}
}

pair<string, float> cStudent::najlepsza_ocena() {
	sort(oceny.begin(), oceny.end(), po_ocenach);
	pair<string, float> ocena = *oceny.begin();
	return ocena;
}

vector<cStudent>::iterator szukanie_studenta(vector<cStudent>& studenci, string& nazwisko) {
	vector<cStudent>::iterator itr = find_if(studenci.begin(), studenci.end(), [nazwisko](const auto &student) {
		return nazwisko == student.nazwisko;
	});
	return itr;
}

bool po_nazwisku(cStudent s1, cStudent s2) {
	if (s1.nazwisko < s2.nazwisko) return true;
	if (s1.nazwisko == s2.nazwisko) {
		if (s1.imie < s2.imie) return true;
		if (s1.imie == s1.imie)
			return s1.rok_urodzenia < s2.rok_urodzenia;
	}
	return false;
}

bool po_roku(cStudent s1, cStudent s2) {
	if (s1.rok_urodzenia < s2.rok_urodzenia) return true;
	if (s1.rok_urodzenia == s2.rok_urodzenia) {
		if (s1.nazwisko < s2.nazwisko) return true;
		if (s1.nazwisko == s2.nazwisko)
			return s1.imie < s2.imie;
	}
	return false;
}

bool po_imieniu(cStudent s1, cStudent s2) {
	if (s1.imie < s2.imie) return true;
	if (s1.imie == s2.imie) {
		if (s1.nazwisko < s2.nazwisko)return true;
		if (s1.nazwisko == s2.nazwisko)
			return s1.rok_urodzenia < s2.rok_urodzenia;
	}
	return false;
}

bool po_srednich(cStudent s1, cStudent s2) {
	if (s1.srednia() > s2.srednia()) return true;
	if (s1.srednia() == s2.srednia()) {
		if (s1.nazwisko > s2.nazwisko) return true;
		if (s1.nazwisko == s2.nazwisko) {
			if (s1.imie > s2.imie) return true;
			if (s1.imie == s1.imie)
				return s1.rok_urodzenia < s2.rok_urodzenia;
		}
	}
	return false;
}

bool po_ocenach(pair<string, float> o1, pair<string, float> o2)
{
	if (o1.second > o2.second) return true;
	if (o1.second == o2.second) {
		if (o1.first < o2.first) return true;
	}
	return false;
}

cStudent parsuj(string osoba) {
	stringstream str(osoba);
	string imie, nazwisko, data_urodzenia, plec;
	vector<pair<string, float>> oceny;
	getline(str, imie, ';');
	getline(str, nazwisko, ';');
	getline(str, data_urodzenia, ';');
	getline(str, plec, ';');
	int rok_urodzenia = stoi(data_urodzenia);

	while (!str.eof())
	{
		pair<string, float> ocena;
		string przedmiot;
		string wartosc;
		getline(str, przedmiot, ';');
		if (str.fail())
			break;
		getline(str, wartosc, ';');
		float oc = stof(wartosc);
		ocena.first = przedmiot;
		ocena.second = oc;
		oceny.push_back(ocena);
	}

	cStudent s1;
	s1.imie = imie;
	s1.nazwisko = nazwisko;
	s1.rok_urodzenia = rok_urodzenia;
	s1.plec = plec;

	for (int i = 0; i < oceny.size(); i++) {
		s1.oceny.push_back(oceny[i]);
	}

	return s1;
}

string zapisz(vector<cStudent> studenci) {
	string napis;
	for (int i = 0; i < studenci.size(); i++) {
		if (i != 0) napis += '\n';
		napis += studenci[i].imie;
		napis += ";";
		napis += studenci[i].nazwisko;
		napis += ";";
		stringstream ss;
		ss << studenci[i].rok_urodzenia;
		string data_urodzenia = ss.str();
		napis += data_urodzenia;
		napis += ";";
		napis += studenci[i].plec;
		for (int j = 0; j < studenci[i].oceny.size(); j++) {
			napis += ";";
			napis += studenci[i].oceny[j].first;
			napis += ";";
			stringstream ss1;
			ss1 << (float)studenci[i].oceny[j].second;
			string oc = ss1.str();
			napis += oc;
		}
	}
	return napis;
}