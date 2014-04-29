#ifndef ASC_HH_
#define ASC_HH_
#include <vector>
#include <string>

 using namespace std;

/*!
 * \file
 * \brief Definiuje klase Asc i jej metody
 */

/*! \brief Klasa tablicy asocjacyjnej
 * 
 */
class Asc 
{
	public:


/*! \brief Definiuje strukture Para, ktora sklada sie
 * z klucza typu string i jego wartosci jako typ int.
 * 
 */
	struct Para
	{
		string klucz;
		int wartosc;
	};

/*! \brief Definiuje strukture danych ze std::vector.
 * 
 */
	vector<Para> tabasoc;

	void dodaj(int wartosc, string klucz);

	void usun(string klucz);

	int pobierz(string klucz);

	bool czypusta();

	int zlicz();

	void zastap(int nowa, string klucz);

	int indeks(string klucz);
};

#endif
