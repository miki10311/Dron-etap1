#ifndef SWektor_HH
#define SWektor_HH

/*!
 *  \file
 *  \brief Definicja klasy SWektor
 *
 *  Plik zawiera definicję klasy SWektor, która
 *  jest szablonem do operacji na wektorach.
 *
 */

#include <iostream>
using namespace std;

/*!
 *  \brief Klasa 'SWektor' opisuje nam pojęcie wektora i zawiera
 *  elementy niezbędne do wykonywania operacji na wektorach.
 *  
 *  Prywatne:
 *     tab                - tablica, dzieki ktorej zapisujemy macierz.
 *     static aktualna    - ilosc aktualnie widzianych obiektow
 *     static wszystkie   - ilosc obiektow w sumie
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Przeciążenia operatorów arytmetycznych umożliwiają:
 *     - dodawanie i odejmowanie wektorów
 *     - mnożenie macierzy przez wektor
 *     - mnożenie i dzielenie wektora przez liczbę
 *
 *     Konstruktor bezparametryczny, kopiujący, destruktor - dodane,
 *                    aby zrealizowac zliczanie ilosci obiektow
 *
 *     Metody wezaktualna() i wezwszystkie() przekazują dalej ilośc obiektów.
 *
 */
template <typename typ, int ROZMIAR>
class SWektor{

/*!
* \brief Tablica
*
* Tablica, dzieki ktorej zapisujemy macierz.
*/
  typ tab[ROZMIAR];

/*!
* \brief Aktualna liczba obiektów
*/
  static int aktualna;

/*!
* \brief Ilość obiektów w sumie
*/
  static int wszystkie;





  public:

  SWektor() //konstruktor bezparametryczny
  {
    ++aktualna;
    ++wszystkie;
  }


  SWektor(const SWektor<typ,ROZMIAR> & wek) //konstruktor kopiujacy
  {
    tab[0]=wek[0];
    tab[1]=wek[1];
    tab[2]=wek[2];
    ++aktualna;
    ++wszystkie;
  }


  ~SWektor() //dekstruktor
  {
    --aktualna;
  }


/*!
 * \brief Dostarczaja zwracana zmienna do użytku w programie. 
 * Argumenty:
 *    \param[in] aktualna  - aktualna liczba obiektow
 * Zwraca:
 *    \return Aktualna liczbe obiektow.
 */
  static int wezaktualna(){return aktualna;}


/*!
 * \brief Dostarczaja zwracana zmienna do użytku w programie. 
 * Argumenty:
 *    \param[in] wszystkie  - liczba obiektow w sumie
 * Zwraca:
 *    \return Liczbe obiektow w sumie.
 */
  static int wezwszystkie(){return wszystkie;}


/*!
 * \brief Dostarcza zmienną, na której możemy pracować. 
 * Argumenty:
 *    \param[in] i - indeks
 * Zwraca:
 *    \return Cala oryginalną zmienną. 
 */
  typ & operator[](int i);
  

 
/*!
 * \brief Dostarcza stałą wartość. 
 * Argumenty:
 *    \param[in] i - indeks
 * Zwraca:
 *    \return Samą wartość.
 */
  typ operator[](int i) const;




/*!
 * \brief Realizuje dodawanie dwoch wektorow (jeden z macierzy).
 * Argumenty:
 *    \param[in] tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] Skl2   - wektor
 * Zwraca:
 *    \return Wektor, jako suma wektorow.
 */
  SWektor<typ,ROZMIAR> operator + (SWektor<typ,ROZMIAR> skl2);




/*!
 * \brief Realizuje odejmowanie dwoch wektorow (jeden z macierzy).
 * Argumenty:
 *    \param[in] tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] Skl2   - wektor
 * Zwraca:
 *    \return Wektor, jako roznica wektorow.
 */
  SWektor<typ,ROZMIAR> operator - (SWektor<typ,ROZMIAR> skl2);




/*!
 * \brief Realizuje mnozenie wektora przez macierz.
 * Argumenty:
 *    \param[in] tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] Skl2   - wektor
 * Zwraca:
 *    \return Liczbe, jako wynik działania.
 */
  typ operator * (SWektor<typ,ROZMIAR> skl2);




/*!
 * \brief Realizuje mnozenie wektora (z macierzy) przez liczbę. 
 * Argumenty:
 *    \param[in] tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] Skl2   - liczba
 * Zwraca:
 *    \return Wektor, jako wynik działania.
 */
  SWektor<typ,ROZMIAR> operator * (typ skl2);




/*!
 * \brief Realizuje dzielenie wektora (z macierzy) przez liczbę. 
 * Argumenty:
 *    \param[in] tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] Skl2   - liczba
 * Zwraca:
 *    \return Wektor, jako wynik działania.
 */
  SWektor<typ,ROZMIAR> operator /(typ skl2);

};



/*!
 * \brief Funkcja służy do przypisania wartosci Wektora ze standartowego wejscia.
 * Argumenty:
 *    \param[in] operator     - zawiera symbol operatora                            
 *    \param[in] Strm, Wek    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    \return Obiekt typu istream.
 */
template <typename typ, int ROZMIAR>
std::istream & operator >> (std::istream &Strm, SWektor<typ,ROZMIAR> &Wek)
{
  for (int i=0; i<ROZMIAR; i++)
  Strm >> Wek[i];
  
  return Strm;
}


//opisane wyzej w ciele klasy
template <typename typ, int ROZMIAR>
int SWektor<typ,ROZMIAR>::aktualna=0;


//opisane wyzej w ciele klasy
template <typename typ, int ROZMIAR>
int SWektor<typ,ROZMIAR>::wszystkie=0;

/*!
 * \brief Funkcja służy do wypisywania watrosci Wektora na standardowe wyjście.
 * Argumenty:
 *    \param[in] operator     - zawiera symbol operatora                            
 *    \param[in] Strm, Wek    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    \return Obiekt typu ostream.
 */
template <typename typ, int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const SWektor<typ,ROZMIAR> &Wek)
{
  for (int i=0; i<ROZMIAR; i++)
  Strm << Wek[i] << "\t";
  
  return Strm;
}



//opisane wyzej w ciele klasy
template <typename typ, int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator + (SWektor<typ,ROZMIAR> skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]+skl2[i];
  
  return wynik;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator - (SWektor<typ,ROZMIAR> skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]-skl2[i];
  
  return wynik; 
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
typ SWektor<typ,ROZMIAR>::operator * (SWektor<typ,ROZMIAR> skl2)
{
  typ suma=0;
  for (int i=0; i<ROZMIAR; i++)
  suma+=tab[i]*skl2[i];
  
  return suma;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator * (typ skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]*skl2;
  
  return wynik;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator / (typ skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]/skl2;

  return wynik;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
typ & SWektor<typ,ROZMIAR>::operator[] (int i)
{
  return tab[i];
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
typ  SWektor<typ,ROZMIAR>::operator[] (int i) const
{
  return tab[i];
}




#endif