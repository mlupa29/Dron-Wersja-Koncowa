#ifndef PPRZESZKODA_HH
#define PPRZESZKODA_HH


#include "Przeszkoda.hh"

#include "Prostopadloscian.hh"

class P_Prostopadloscian :public Przeszkoda
{


public:

P_Prostopadloscian(double x,double y,double z,std::shared_ptr<drawNS::Draw3DAPI> &api):Przeszkoda(x,y,z,api)
{


}
bool czy_kolizja(Wektor3D srodek,double promien_drona)
{
 
if(sqrt(pow((get_srodek()[0]-srodek[0]),2)+pow((get_srodek()[1]-srodek[1]),2)+pow((get_srodek()[2]-srodek[2]),2)) <sqrt(pow((krzywa[0][0][0]-this->srodek[0]),2)+pow((krzywa[0][0][1]-this->srodek[1]),2)+pow((krzywa[0][0][2]-this->srodek[2]),2))+this->promien()+promien_drona)
{

  cout<<"Kolizja"<<endl;
  return true;
}
else{
  return false;
}

}



};




#endif


