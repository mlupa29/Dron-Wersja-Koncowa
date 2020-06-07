#include <iostream>
#include <unistd.h>
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Powierzchnia.hh"
#include "Dno.hh"
#include "Graniastoslup.hh"
#include "Dron.hh"
#include "P_Prostopadloscian.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using namespace std;


void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}



int main() {
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-60,60,-60,60,-60,60,0)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  



 /*!
  *\brief Powstanie powierzchni oraz dna
  * Iniciuje powstanie dna oraz powierzchni
  * 
  */
 Powierzchnia po(api);
 Dno d(api);


vector<shared_ptr<Przeszkoda> > przeszkody;
przeszkody.push_back(make_shared<P_Prostopadloscian>(3,4,12,api));
przeszkody.push_back(make_shared<P_Prostopadloscian>(0,6,15,api));
przeszkody.push_back(make_shared<P_Prostopadloscian>(0,0,20,api));
przeszkody.push_back(make_shared<P_Prostopadloscian>(10,0,20,api));

d.rysuj();
po.rysuj();
 przeszkody[0]->ruch(30,0);
przeszkody[0]->rysuj();

 przeszkody[1]->ruch(20,140);
 przeszkody[1]->rysuj();



 przeszkody[2]->ruch(30,298);

 przeszkody[2]->rysuj();


 przeszkody[3]->ruch(30,280);
 przeszkody[3]->pion(34,90);
 przeszkody[3]->rysuj();

Dron dron(api);
dron.start();
 
// Dron dron2(api);
// dron2.goradol(&p);

// dron2.start();


/*!
  *\brief Petla wyboru funkcji
  * Pozwala uzytkownikowi na uzycie wybranej przez niego funkcji
  * 
  */
int liczbafigur=Bryla::pokazfigury();
char men = 'h';

while(men!='q'){
cout<<"wybierz opcje:"<<endl;
cout<<"p - przesuniecie"<<endl;
cout<<"o - obrot"<<endl;
cout<<"g - przesuniecie gora/dol"<<endl;
cout<<"q - koniec"<<endl;
cout<<"liczba figur na ten moment to: "<<liczbafigur<<endl;

  std::cin>>men;

switch(men){


 
case 'p':
{
 dron.przod(przeszkody);
 
  break;

}


case 'g':
{
 dron.goradol(przeszkody);

  break;


}



case 'o':
{  dron.obrot();

break;
}
default:
{
  continue;
}
}
}
}



 

