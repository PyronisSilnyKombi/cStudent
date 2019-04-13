#include"cStudent_header.h"

int main()
{
	vector<cStudent> studenci;

	for (;;)
	{
		int wybor = menu();

		switch (wybor) {
		case 1: {
			int n;
			cout << "Ilu studnetow chcesz wprowadzic : ";
			cin >> n;
			system("cls");

			for (int i = 0; i < n; i++) {
				cStudent s1;
				studenci.push_back(s1.zwroc());
			}
			system("pause");
			system("cls");
			break;
		}

		case 2: {
			cout << "Podaj nazwisko studenta, ktorego oceny chcesz wprowadzic" << endl;
			string nazwisko;
			cin.ignore();
			getline(cin, nazwisko);
			vector<cStudent>::iterator itr;

			itr = szukanie_studenta(studenci, nazwisko);

			system("cls");
			if (itr == studenci.end()) { cout << "Blad wprowadzania, nie istniejacy student" << endl; system("pause"); system("cls"); break; }
			else { cout << "Student znaleziony" << endl; }
			itr->pobierz_oceny(studenci);

			cout << "Wprowadzone oceny : " << endl;
			itr->wyswietl_oceny();

			system("pause");
			system("cls");
			break;
		}

		case 3: {
			for (;;)
			{
				int wybor_sort = menu_sort();
				switch (wybor_sort)
				{
				case 1: {
					cout << "Sortowanie po nazwisku" << endl;
					sort(studenci.begin(), studenci.end(), po_nazwisku);
					break;
				}

				case 2: {
					cout << "Sortowanie po imieniu" << endl;
					sort(studenci.begin(), studenci.end(), po_imieniu);
					break;
				}

				case 3: {
					cout << "Sortowanie po dacie urodzenia" << endl;
					sort(studenci.begin(), studenci.end(), po_roku);
					break;
				}

				default: {
					cout << "PODAJ POPRAWNA LICZBE !!!" << endl;
					cin.ignore();
				}
				}break;
			}
			for (int i = 0; i < studenci.size(); i++) {
				studenci[i].wyswietl();
			}system("pause");
			system("cls");
			break;
		}

		case 4: {
			sort(studenci.begin(), studenci.end(), po_srednich);
			studenci.begin()->wyswietl();
			cout << "Srednia : " << studenci.begin()->srednia() << endl;
			system("pause");
			system("cls");
			break;
		}

		case 5: {
			cout << "Najlepsze oceny studentow" << endl;
			for (int i = 0; i < studenci.size(); i++) {
				/*cout << studenci[i].nazwisko << " " << studenci[i].imie << " : ";*/
				studenci[i].wyswietl();
				pair<string, float> ocena = studenci[i].najlepsza_ocena();
				cout << ocena.first << " " << ocena.second << endl;
			}
			system("pause");
			system("cls");
			break;
		}

		case 6: {
			string przedmiot;
			cout << "Podaj przedmiot dla ktorego ma byc wyliczona srednia : ";
			cin.ignore();
			getline(cin, przedmiot);

			int divider = 0;
			float suma = 0;
			vector <pair<string, float>> st_sr;
			for (int i = 0; i < studenci.size(); i++) {
				suma += studenci[i].srednia_z_przedmiotu(przedmiot, divider);
			}
			cout << "Srednia z przedmiotu " << przedmiot << " wynosi : " << suma / divider << endl;

			system("pause");
			system("cls");
			break;
		}

		case 7: {
			cout << "Podaj przedmiot wedlug ktorego ma byc posortowana lista : ";
			string przedmiot;
			cin.ignore();
			getline(cin, przedmiot);
			vector <pair<string, float>> st_sr;
			for (int i = 0; i < studenci.size(); i++) {
				st_sr.push_back(studenci[i].srednia_z_przedmiotu(przedmiot));
			}
			sort(st_sr.begin(), st_sr.end(), [](const pair<string, float> s1, const pair<string, float> s2) {return s1.second > s2.second; });

			for (auto& el : st_sr) {
				cout << el.first << " " << el.second << endl;
			}

			system("pause");
			system("cls");
			break;
		}

		case 8: {
			cout << "Wczytywanie z pliku" << endl;

			//dodaæ funkcje umo¿liwiajace zapis i odczyt danych z pliku.
			//W pliku tekstowym w ka¿dej linii powinny byæ umieszczone dane ka¿dej z osób wraz z ocenami(uwaga liczba przedmiotów mo¿e byæ ró¿na u ka¿dej z osób)

			fstream strumien("dane_osob.txt", ios::in);

			if (strumien.is_open()) {
				while (!strumien.eof()) {
					string osoba;
					getline(strumien, osoba);

					cStudent s1 = parsuj(osoba);


					studenci.push_back(s1);

					//float wart;
					//pair<int, float> para;
					///*strumien >> lp >> wart;*/
					//string tmp;
					//getline(strumien, tmp, ';');
					//if (strumien.fail())
					//	break;
					//lp = stoi(tmp);
					//getline(strumien, tmp);
					//wart = stof(tmp);
					//para.first = lp;
					//para.second = wart;
					//wyniki.push_back(para);

					//cout << lp << " - " << wart << endl;

				}
				strumien.close();
			}
			else {
				cout << "Nie udalo sie otworzyc pliku." << endl;
			}

			system("pause");
			system("cls");
			break;
		}

		case 9: {
			cout << "9 - Zapis do pliku" << endl;
			//dodaæ funkcje umo¿liwiajace zapis i odczyt danych z pliku.
			//W pliku tekstowym w ka¿dej linii powinny byæ umieszczone dane ka¿dej z osób wraz z ocenami(uwaga liczba przedmiotów mo¿e byæ ró¿na u ka¿dej z osób)

			fstream strumien("dane_osob.txt", ios::out);

			if (strumien.is_open()) {

				string napis = zapisz(studenci);
				strumien << napis;

				/*string osoba;
				getline(strumien, osoba);
				sStudent s1 = parsuj(osoba);
				studenci.push_back(s1);*/

				//float wart;
				//pair<int, float> para;
				///*strumien >> lp >> wart;*/
				//string tmp;
				//getline(strumien, tmp, ';');
				//if (strumien.fail())
				//	break;
				//lp = stoi(tmp);
				//getline(strumien, tmp);
				//wart = stof(tmp);
				//para.first = lp;
				//para.second = wart;
				//wyniki.push_back(para);

				//cout << lp << " - " << wart << endl;

				strumien.close();
			}
			else {
				cout << "Nie udalo sie otworzyc pliku." << endl;
			}


			system("pause");
			system("cls");
			break;
		}

		case 10: {
			cout << "Usuwanie studenta" << endl;

			cout << "Podaj nazwisko studenta, ktorego chcesz usunac" << endl;
			string nazwisko;
			cin.ignore();
			getline(cin, nazwisko);
			vector<cStudent>::iterator itr;

			itr = szukanie_studenta(studenci, nazwisko);
	
			system("cls");
			if (itr == studenci.end()) { cout << "Blad wprowadzania, nie istniejacy student" << endl; system("pause"); system("cls"); break; }
			else { cout << "Student znaleziony" << endl; }
			studenci.erase(itr);

			system("pause");
			system("cls");
			break;
		}

		case 11: {
			cout << "Usuwanie przedmiotu" << endl;

			cout << "Podaj nazwe przedmiotu, ktory chcesz usunac" << endl;
			string przedmiot;
			cin.ignore();
			getline(cin, przedmiot);

			for (int i = 0; i < studenci.size(); i++) {
				studenci[i].usun_oceny(przedmiot);
			}

			system("pause");
			system("cls");
			break;
		}

		default: {
			cout << "PODAJ POPRAWNA LICZBE !!!" << endl;
			cin.ignore();
		}
		}
	}

	system("pause");
	return 0;
}