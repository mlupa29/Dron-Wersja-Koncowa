#pragma once
#include <iostream>
#include <unistd.h>
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "interfdron.hh"
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using namespace std;

/*!
 *\file Plik "Dron"
 *\brief Plik zawiera w sobie skladowe klasy Dron
 *
 *Klasa modeluje pojecie Drona skladajacego sie z Prostopadloscianu oraz 2 srub 
 *o zadanej dlugosci boku.
 *Ruch samego drona oraz jego srub jest animowany oraz odbywa sie na zasadach poruszania 
 *porownywalnych to rzeczywistego ruchu takiego drona w srodowisku wodnym.
 *
 */


class Dron : public IDron 
{
std::shared_ptr<drawNS::Draw3DAPI> &api;
 Granaistoslup *s1;
  Granaistoslup *s2;
  Prostopadloscian *a;
public:

 /*!
  *\brief Konstruktor klasy Dron
  * Modul modeluje pojecie drona o zadanych figurach o zadanych dlugosciach, szerokosciach , wysokosciach 
  * Iniciuje powstanie zadanych obiektow
  */




Dron(std::shared_ptr<drawNS::Draw3DAPI> &api):api(api)
{
 a= new Prostopadloscian(10,10,10,api);
  s1= new Granaistoslup(3,3,3,api);
  s2= new Granaistoslup(3,3,3,api);
}

/*!
  *\brief Rysowanie elementow w programie graficznym gnuplot
  * Metody rysujace wymienione w wyzszej czesci dokumentacji figury oraz 
  * ma za zadanie ustawienie srub wzgledem drona. 
  * 
  */


bool czy_kolizjadol(double promien_drona){
  if( a->get_srodek()[2]>-40+promien_drona){return true;
  
  }
  else{cout<<"Kolizja"<<endl;return false;}
}

bool czy_kolizjagora(double promien_drona){
  if(a->get_srodek()[2]<30  ){return true;
  
  }
  else{cout<<"Kolizja"<<endl;return false;}
}

void start()
 {


 a->ruch(0,0);
 a->rysuj(); 
  s2->przesun(a->get_wirz(0,3));
  s2->ruch(0,0);
 s2->rysuj();
 
 s1->przesun(a->get_wirz(0,2));
 s1->ruch(0,0);
 s1->rysuj();
  
  

}

 /*!
  *\brief Metoda umozliwiajaca poruszanie sie dronem w przod
  * Metoda umozliwia poruszanie sie dronem na zadana odleglosc do przodu.
  * Ruch drona jest animowany poprzez odpowiedni dobor parametrow spowalniajacych dzialanie 
  * funkcji i sklada sie on z postepujacych po sobie malych przesuniec dla drona wraz z jego
  * srubami ktorych obrot jest skierowany w przeciwnych kierunkach obrotu .
  * 
  * \param[in] przesun - liczba mikro ruchow o ktore przesunie sie dron
  */

  void przod(vector<shared_ptr<Przeszkoda> > p)
 {

     cout<<"Podaj przesuniecie"<<endl;
 double przesun; 
 cin>>przesun;
 
 for(int i=0; i<przesun ; i++)
{
if(!p[0]->czy_kolizja(a->get_srodek(),a->promien())&&!p[1]->czy_kolizja(a->get_srodek(),a->promien())&&!p[2]->czy_kolizja(a->get_srodek(),a->promien())&&!p[3]->czy_kolizja(a->get_srodek(),a->promien())){
  a->ruch(1,0);
  s1->ruch(1,0);
  s1->rysuj();
  s2->ruch(1,0);
  s2->rysuj();
  
  s1->osx(0,10);
  s2->osx(0,-10);
  a->rysuj();
  
  usleep(100000);
}
else{a->ruch(-1,0);
  s1->ruch(-1,0);
  s1->rysuj();
  s2->ruch(-1,0);
  s2->rysuj();
  a->rysuj();}
}
}

/*!
  *\brief Metoda umozliwiajaca obracanie sie dronem o wybrany kat
  * Metoda umozliwiajaca obrot drona o dany kat.
  * Ruch drona jest animowany poprzez odpowiedni dobor parametrow spowalniajacych dzialanie 
  * funkcji i sklada sie on z postepujacych po sobie malych przesuniec dla drona wraz z jego
  * srubami ktorych obrot jest skierowany w przeciwnych kierunkach obrotu 
  * 
  * \param[in] k - liczba mikro ruchow o ktore obroci sie dron
  */
  void obrot()
 {

     std::cout<<"Podaj kat"<<std::endl;
  double k;
  std::cin>>k;

   for(int i=0; i<k; i++)
{
    a->ruch(0,1);
    
  s1->przesun(a->get_wirz(0,2));
     s2->przesun(a->get_wirz(0,3));
      s1->ruch(0,1);
       s2->ruch(0,1);
       s1->osx(0,10);
  s2->osx(0,-10);
  s1->rysuj();
 
   
  s2->rysuj();
  a->rysuj(); 
   usleep(60000);
}
}

 /*!
  *\brief Metoda umozliwiajaca poruszanie sie dronem w gore lub dol oraz naprzod lub do tylu pod wybranym katem opadania lub wznoszenia
  * Metoda umozliwia poruszanie sie dronem na zadana odleglosc oraz pod wybranym katem.
  * Ruch drona jest animowany poprzez odpowiedni dobor parametrow spowalniajacych dzialanie 
  * funkcji i sklada sie on z postepujacych po sobie malych przesuniecdla drona wraz z jego
  * srubami ktorych obrot jest skierowany w przeciwnych kierunkach obrotu 
  * 
  * \param[in] przesu - liczba mikro ruchow o ktore przesunie sie dron
  * \param[in] kat - liczba stopni okreslajaca kierunek ruchu
  */

  void goradol(vector<shared_ptr<Przeszkoda> > p)
 {

     cout<<"Podaj przesuniecie"<<endl;
 double przesu; 
 cin>>przesu;
 cout<<"Podaj kat"<<endl;
 double kat; 
 cin>>kat;
 
 for(int i=0; i<przesu ; i++)
{
  if(!p[0]->czy_kolizja(a->get_srodek(),a->promien())&&!p[1]->czy_kolizja(a->get_srodek(),a->promien())&&!p[2]->czy_kolizja(a->get_srodek(),a->promien())&&!p[3]->czy_kolizja(a->get_srodek(),a->promien())&&czy_kolizjadol(a->promien())&&czy_kolizjagora(a->promien()))
  {
  a->pion(1,kat);
  s1->pion(1,kat);
  s2->pion(1,kat);
  s1->rysuj();
 s2->rysuj();
 s1->osx(0,10);
  s2->osx(0,-10);
  a->rysuj();
   usleep(100000);
}
else if(!p[0]->czy_kolizja(a->get_srodek(),a->promien())&&!p[1]->czy_kolizja(a->get_srodek(),a->promien())&&!p[2]->czy_kolizja(a->get_srodek(),a->promien())&&!p[3]->czy_kolizja(a->get_srodek(),a->promien())&&czy_kolizjadol(a->promien())&&!czy_kolizjagora(a->promien())) 
{a->pion(1,90);
  s1->pion(1,90);
  s2->pion(1,90);
  s1->rysuj();
 s2->rysuj();
  a->rysuj();
}
else if(!p[0]->czy_kolizja(a->get_srodek(),a->promien())&&!p[1]->czy_kolizja(a->get_srodek(),a->promien())&&!p[2]->czy_kolizja(a->get_srodek(),a->promien())&&!p[3]->czy_kolizja(a->get_srodek(),a->promien())&&!czy_kolizjadol(a->promien())&&czy_kolizjagora(a->promien())) 
{a->pion(1,-90);
  s1->pion(1,-90);
  s2->pion(1,-90);
  s1->rysuj();
 s2->rysuj();
  a->rysuj();
}

}
 }
 };
