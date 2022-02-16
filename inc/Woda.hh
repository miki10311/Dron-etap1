#ifndef WODA_HH
#define WODA_HH

/*!
 *  \file
 *  \brief Definicja klasy Woda
 *
 *  Plik zawiera definicję klasy Woda, która
 *  modeluje powierzchnię górną.
 *
 */

#include "PowierzchniaGeom.hh"

/*!
 *  \brief Klasa 'Woda' opisuje powierzchnię wody
 *  
 *  Prywatne:
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Metoda 'Woda' opisujaca powierzchni wody
 *     Metoda size() lamanych zwracajaca rozmiar
 */
class Woda: public PowierzchniaGeom//dziedziczenie
{
public:


/*!
 * \brief Metoda definiuje powierzchnię wody. 
 * Argumenty:
 *    \param[in] szerokosc   - szerokosc powierzchni wody
 *    \param[in] wys         - wysokosc fal powierzchni wody
 *    \param[in] dlugosc     - dlugosc powierzchni wody
 *    
 * Zwraca:
 *    -
 */
Woda(double szerokosc=100, double dlugosc=100 ,double pow=40, double wys=5)
{
  for(int i=0; i<szerokosc; i+=10)
  {
   TabLamanych.resize(TabLamanych.size()+1);
   for(int j=0; j<dlugosc; j+=10)
   {
      TabLamanych[i/10].Wierz.resize(TabLamanych[i/10].Wierz.size()+1);
      TabLamanych[i/10].Wierz[j/10][0]=-szerokosc/2+i;
      TabLamanych[i/10].Wierz[j/10][1]=-dlugosc/2+j;
      if((j/10)%2==0)
      TabLamanych[i/10].Wierz[j/10][2]=pow;
      else
      TabLamanych[i/10].Wierz[j/10][2]=pow+wys;
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
std::ostream  &operator << (std::ostream  &Strm, Woda prost)
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