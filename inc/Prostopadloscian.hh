#ifndef Prostopadloscian_HH
#define Prostopadloscian_HH

/*!
 *  \file
 *  \brief Definicja klasy Prostopadloscian
 *
 *  Plik zawiera definicję klasy Prostopadloscian, która
 *  jest widocznym obrazem drona.
 *
 */

#include "PowierzchniaGeom.hh"

/*!
 *  \brief Klasa 'Prostopadloscian' opisuje nam figure drona i zawiera
 *  elementy niezbędne do wygladu drona.
 *  
 *  Prywatne:
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Metoda 'prostopadloscian' opisujaca rysowanie drona
 *     Metoda size() lamanych zwracajaca rozmiar
 */
class Prostopadloscian: public PowierzchniaGeom //dziedziczenie
{
public:


/*!
 * \brief Metoda definiuje prostopadłościan. 
 * Argumenty:
 *    \param[in] x,y,z       - współrzędne początkowego położenia drona
 *    \param[in] szerokosc   - szerokosc drona
 *    \param[in] wysokosc    - wysokosc drona
 *    \param[in] dlugosc     - dlugosc drona
 * Zmienne:
 *    suma_kat    - zmienna okreslajaca odniesienie do operacji obrotu
 *    nowa        - okresna wspolzedne kolejnych lamanych
 *    nowy        - okresla wektor przesuniecia do kolejnego wierzcholka
 *    srodek      - tablica przechowujaca srodek drona
 *    
 * Zwraca:
 *    -
 */
Prostopadloscian(double x=0, double y=0, double z=0, double szerokosc=10, double wysokosc=10, double dlugosc=10)
{
  
   suma_kat=0;
   Wektor3D nowy;
   Lamana nowa;
   
   nowy[0]=x;
   y=-dlugosc/2;
   nowy[1]=dlugosc/2;
   nowy[2]=z;

   srodek=nowy;
   srodek[0]=0;
   srodek[1]=0;
   srodek[2]=0;


   // kolejne wierzcholki prostopadloscianu
   nowa.Wierz.push_back(nowy);// dodaje na koniec tablity nowy element
   TabLamanych.push_back(nowa);
   nowy[0]=x+szerokosc;
   nowy[1]=y;
   nowy[2]=z+wysokosc;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x+szerokosc;
   nowy[1]=y+dlugosc;
   nowy[2]=z+wysokosc;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x;
   nowy[1]=y+dlugosc;
   nowy[2]=z;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x;
   nowy[1]=y;
   nowy[2]=z;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x+szerokosc;
   nowy[1]=y;
   nowy[2]=z-wysokosc;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x+szerokosc;
   nowy[1]=y+dlugosc;
   nowy[2]=z-wysokosc;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x;
   nowy[1]=y+dlugosc;
   nowy[2]=z;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x;
   nowy[1]=y;
   nowy[2]=z;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x-szerokosc;
   nowy[1]=y;
   nowy[2]=z-wysokosc;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x-szerokosc;
   nowy[1]=y+dlugosc;
   nowy[2]=z-wysokosc;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x;
   nowy[1]=y+dlugosc;
   nowy[2]=z;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x;
   nowy[1]=y;
   nowy[2]=z;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x-szerokosc;
   nowy[1]=y;
   nowy[2]=z+wysokosc;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x-szerokosc;
   nowy[1]=y+dlugosc;
   nowy[2]=z+wysokosc;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x;
   nowy[1]=y+dlugosc;
   nowy[2]=z;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x;
   nowy[1]=y;
   nowy[2]=z;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x+szerokosc;
   nowy[1]=y;
   nowy[2]=z+wysokosc;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x+szerokosc;
   nowy[1]=y+dlugosc;
   nowy[2]=z+wysokosc;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
   nowy[0]=x;
   nowy[1]=y+dlugosc;
   nowy[2]=z;

   nowa.Wierz.push_back(nowy);
   TabLamanych.push_back(nowa);
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
std::ostream  &operator << (std::ostream  &Strm, Prostopadloscian prost)
{
   for(int i=0; i<prost.size(); i++)
   {
      Strm<<prost[i]<<std::endl;;
   }
   return Strm;
}


#endif