/*!
 *  \file
 *  \brief Definicja struktury Lamana
 *
 *  Plik zawiera definicję struktury Lamana, która
 *  modeluje pojedyncze lamane.
 *
 */

#include "Wektor.hh"
#include <vector>

// korzystanie z szablonu Swektor
typedef SWektor<double,3> Wektor3D ;


/*!
 *  \brief Struktura 'Lamana' opisuje nam punkty skladajace sie na linie
 *  
 *  Prywatne:
 *  wierz - współrzedne wierzcholkow jako wektory
 *
 *  Publiczne:
 *
 *
 *
 */
struct Lamana{
std::vector<Wektor3D> Wierz;
};




/*!
 * \brief Funkcja służy do wypisywania watrosci Wektora na standardowe wyjście.
 * Argumenty:
 *    \param[in] operator     - zawiera symbol operatora                            
 *    \param[in] Strm, prost  - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    \return Obiekt typu ostream.
 */
std::ostream  &operator << (std::ostream  &Strm, Lamana prost)
{
    for(unsigned int i=0; i<prost.Wierz.size(); i++)
    {
        if(i%4==0)
        Strm<<std::endl;
        
        Strm<<prost.Wierz[i]<<std::endl;
    }
    return Strm;
}
