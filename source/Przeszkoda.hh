#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "Bryla.hh"

class Przeszkoda:public Prostopadloscian 
{


public:

Przeszkoda(double x,double y,double z,std::shared_ptr<drawNS::Draw3DAPI> &api):Prostopadloscian(x,y,z,api){};
virtual bool czy_kolizja(Wektor3D srodek,double promien_drona)=0;


};



#endif