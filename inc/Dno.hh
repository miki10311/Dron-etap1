#ifndef DNO_HH
#define DNO_HH

/*!
 *  \file
 *  \brief Definicja klasy Dno
 *
 *  Plik zawiera definicję klasy Dno, która
 *  opisuje dolną granicę poruszania się drona.
 *
 */

#include "PowierzchniaGeom.hh"

/*!
 *  \brief Klasa 'Dno' opisuje powierzchnię dna
 *  
 *  Prywatne:
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Metoda 'Dno' opisujaca rysowanie dna
 *     Metoda size() lamanych zwracajaca rozmiar
 */
class Dno: public PowierzchniaGeom//dziedziczenie
{
public:


/*!
 * \brief Metoda definiuje powierzchnię wody. 
 * Argumenty:
 *    \param[in] szerokosc   - szerokosc powierzchni wody
 *    \param[in] dno         - poziom dna
 *    \param[in] dlugosc     - dlugosc powierzchni wody
 *    
 * Zwraca:
 *    -
 */
Dno(double szerokosc=100, double dlugosc=100 ,double dno=-40)
{
   for(int i=0; i<szerokosc; i+=10)
   {
      TabLamanych.resize(TabLamanych.size()+1);
      for(int j=0; j<dlugosc; j+=10)
      {
         TabLamanych[i/10].Wierz.resize(TabLamanych[i/10].Wierz.size()+1);
         TabLamanych[i/10].Wierz[j/10][0]=-szerokosc/2+i;
         TabLamanych[i/10].Wierz[j/10][1]=-dlugosc/2+j;
         TabLamanych[i/10].Wierz[j/10][2]=dno;
      }
   }
}

/*!
 * \brief Określa rozmiar. 
 * Argumenty:
 *    \param[in] TabLamanych - tablica zawierajaca informacje o rysowanych liniach
 * Zwraca:
 *    \return Rozmiar zmiennej TabLamanych. 
 */
int size()
{
   return TabLamanych.size();
}



/*!
 * \brief Dostarcza zmienną, na której możemy pracować. 
 * Argumenty:
 *    \param[in] i - indeks
 * Zwraca:
 *    \return Cala oryginalną zmienną. 
 */
Lamana operator [](int i) const
{
   return TabLamanych[i];
}



/*!
 * \brief Dostarcza stałą wartość. 
 * Argumenty:
 *    \param[in] i - indeks
 * Zwraca:
 *    \return Samą wartość.
 */
Lamana &operator [](int i)
{
   return TabLamanych[i];
}


};


/*!
 * \brief Funkcja służy do wypisywania watrosci Wektora na standardowe wyjście.
 * Argumenty:
 *    \param[in] operator     - zawiera symbol operatora                            
 *    \param[in] Strm, prost  - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    \return Obiekt typu ostream.
 */
std::ostream  &operator << (std::ostream  &Strm, Dno prost)
{
   for(int i=0; i<prost.size(); i++)
   {
      for(int j=0; j<prost.size(); j++)
      {
         Strm<< prost[i].Wierz[j]<<std::endl;
      }
      Strm<<std::endl;
   }
   return Strm;
}



#endif