#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <unistd.h>
#include "lacze_do_gnuplota.hh"
#include "Prostopadloscian.hh"
#include "Dno.hh"
#include "Woda.hh"

using namespace std;


int main()
{
  PzG::LaczeDoGNUPlota  Lacze;

  fstream plik;
  Prostopadloscian pra(0,-20,0,20,10,10);//(x,y(do przodu),z(prz w gore))
  
  Dno a;
  Woda w;
  
  plik.open("bryly/dno.dat",std::ios::out);
  plik<<a;
  plik.close();

  plik.open("bryly/dron.dat",std::ios::out);
  plik<<pra;
  plik.close();

  plik.open("bryly/woda.dat",std::ios::out);
  plik<<w;
  plik.close();

  Lacze.DodajNazwePliku("bryly/dno.dat");
  Lacze.DodajNazwePliku("bryly/dron.dat");
  Lacze.DodajNazwePliku("bryly/woda.dat");
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-40, 100);
  Lacze.UstawZakresY(-90, 90);
  Lacze.UstawZakresZ(-60, 90);


  Lacze.UstawRotacjeXZ(80,60); // Tutaj ustawiany jest widok

  Lacze.Rysuj(); // Teraz powinno pojawic sie okienko gnuplota

  Wektor3D wek;
  char opcja;
  while(1)
  {
    cout<<"Wybierz opcje: "<<endl;
    cout<<"r - ruch"<<endl;
    cout<<"o - obrot"<<endl;
    cout<<"k - koniec"<<endl<<endl;
    cout<<"Liczba obiektów aktualnie: "<<wek.wezaktualna()<<endl;
    cout<<"Liczba obiektow ogolnie:   "<<wek.wezwszystkie()<<endl;
    cin>>opcja; 

    switch(opcja)
    {
      case 'r':
      {
      double ruch;
      cout<<endl<<"O ile jednostek ma sie poruszyc ?"<<endl;
      cin>>ruch;
      double kat;
      cout<<"Podaj kat opadania: "<<endl;
      cin>>kat;
      for(int i=0; i<ruch; i++)
      {
        pra.ruszaj(1,kat*M_PI/180);
        plik.open("bryly/dron.dat",std::ios::out);
        plik<<pra;
        plik.close();
        Lacze.Rysuj();
        usleep(100000);
      }
    }
    break;



      case 'o':
      double kat;
      cout<<endl<<"Podaj kat obrotu: "<<endl;
      cin>>kat;
      for(int i=0; i<kat; i++)
      {
        pra.obroc(1*M_PI/180); //obrot w radianach
        plik.open("bryly/dron.dat",std::ios::out);
        plik<<pra;
        plik.close();
        Lacze.Rysuj();
        usleep(100000);
      }
      break;


      case 'k':
      return 0;
      break;



      default:
      cout << "BLAD !!!" <<endl<<endl<<endl;
      break;
    }
  }
}
