#include "asc.hh"
#include <iostream>

using namespace std;



/*! \brief Dodaje pare klucz,wartosc do struktury danych std::vector
 * 
 */
void Asc::dodaj(int wartosc, string klucz) 
{
	Para nowa;
	nowa.klucz=klucz;
	nowa.wartosc=wartosc;
	tabasoc.push_back(nowa);
}
/*! \brief Usuwa pare klucz,wartosc na podstawie podanego klucza.
 * Argumentem funkcji erase jest indeks, jaki element posiada w strukturze vector.
 * 
 */
void Asc::usun(string klucz) 
{
	tabasoc.erase(tabasoc.begin()+indeks(klucz));
}
/*! \brief Zwraca wartosc podanego klucza.
 * 
 */
int Asc::pobierz(string klucz) 
{
	return tabasoc[indeks(klucz)].wartosc;
}
/*! \brief Zwraca wartosc logiczna true jezeli rozmiar struktury vector wynosi 0,
 * w przeciwnym wypadku false.
 * 
 */
bool Asc::czypusta() 
{
	if (tabasoc.size()==0)
			return true;
	else return false;
}
/*! \brief Zwraca liczbe elementow, poslugujac sie funkcja size() ze std::vector
 * 
 */
int Asc::zlicz()
{
return tabasoc.size();
}
/*! \brief Przypisuje podanemu kluczowi nowa wartosc
 * 
 */
void Asc::zastap(int nowa, string klucz) 
{
	tabasoc[indeks(klucz)].wartosc=nowa;
}
/*! \brief Zwraca indeks elementu
 * 
 */
int Asc::indeks(string klucz) 
{
	for (int i=0; i<tabasoc.size(); i++)
	{
		if (tabasoc[i].klucz == klucz)
		{
			return i;
		}
	}
}
