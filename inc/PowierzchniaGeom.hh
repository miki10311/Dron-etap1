#ifndef PowierzchniaGeom_HH
#define PowierzchniaGeom_HH

/*!
 *  \file
 *  \brief Definicja klasy PowierzchniaGeom
 *
 *  Plik zawiera definicję klasy PowierzchniaGeom, która
 *  opisuje poruszanie się drona.
 *
 */

#include "Lamana.hh"
#include <cmath>

/*!
 *  \brief Klasa 'PowierzchniaGeom' opisuje nam ruch drona i zawiera
 *  elementy niezbędne do obrotu i ruchu do przodu drona.
 *  
 *  Prywatne:
 *
 *  Publiczne:
 *     TabLamanych - aktualny stan polozenia drona
 *     srodek      - jest to wektor oznaczajacy srodek drona
 *     suma_kat    - zsumowany kat obrotu
 *     
 *     Metoda przesun zawiera zaimplementowany wzor na ruch drona
 *     Metoda obroc zawiera zaimplementowany wzor na obrot drona
 */
class PowierzchniaGeom
{
  public:

/*!
* \brief Aktualny stan polozenia drona.
*/
  std::vector <Lamana> TabLamanych;

/*!
* \brief Wektor bedacy srodkiem drona.
*/
  Wektor3D srodek;

/*!
* \brief Zsumowany kat obrotu.
*/
  double suma_kat;




/*!
 * \brief Realizuje obrot drona.
 * Argumenty:
 *    \param[in] TabLamanych - polozenie poczatkowe
 *    \param[in] srodek      - srodek drona
 *    \param[in] kat         - zadany kat obrotu
 *    \param[in] suma_kat    - zsumowany kat obrotu
 *
 * Zmienne: 
 *    tmp - tablica pomocnicza
 *
 * Zwraca:
 *    -
 */
  void obroc(double kat)
  {
    suma_kat+=kat;

    for(int i=0; i<(int)TabLamanych.size(); i++)
    for(int j=0; j<(int)TabLamanych[i].Wierz.size(); j++)
    {
      double tmp=TabLamanych[i].Wierz[j][0];
      TabLamanych[i].Wierz[j][0]=((tmp-srodek[0])*cos(kat)-(TabLamanych[i].Wierz[j][1]-srodek[1])*sin(kat))+srodek[0];
      TabLamanych[i].Wierz[j][1]=((tmp-srodek[0])*sin(kat)+(TabLamanych[i].Wierz[j][1]-srodek[1])*cos(kat))+srodek[1];
    }
  }




/*!
 * \brief Realizuje ruch drona drona.
 * Argumenty:
 *    \param[in] TabLamanych - polozenie poczatkowe
 *    \param[in] srodek      - srodek drona
 *    \param[in] suma_kat    - zsumowany kat obrotu
 *    \param[in] odleglosc   - przesuniecie
 *
 * Zmienne: 
 *    tmp         - tablica pomocnicza
 *    przes       - zmienna pomocnicza do przesuniecia
 *
 * Zwraca:
 *    -
 */
  void ruszaj(double odleglosc,double kat)
  {
    Wektor3D przes,tmp;
    przes[0]=odleglosc;
    tmp=przes;

    przes[0]=(tmp[0])*cos(suma_kat)-(tmp[1])*sin(suma_kat);
    przes[1]=(tmp[0])*sin(suma_kat)+(tmp[1])*cos(suma_kat);
   
    double tmp2=przes[0];
    przes[0]=(tmp2)*cos(kat)+(przes[2])*sin(kat);
    przes[2]=(tmp2)*-sin(kat)+(przes[2])*cos(kat);
   
    srodek=srodek+przes;
   
    for(int i=0; i<(int)TabLamanych.size(); i++)
    {
      for(int j=0; j<(int)TabLamanych[i].Wierz.size(); j++)
      {
        TabLamanych[i].Wierz[j]=TabLamanych[i].Wierz[j]+przes;
      }
    }
  }

};




#endif