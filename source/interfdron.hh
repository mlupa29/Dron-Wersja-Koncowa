#pragma once 
#include <iostream>
#include <unistd.h>
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "P_Prostopadloscian.hh"
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using namespace std;


 class IDron {
public:
virtual void przod(vector<shared_ptr<Przeszkoda> > p)=0;
virtual void obrot()=0; 
virtual void goradol(vector<shared_ptr<Przeszkoda> > p)=0;
 
 };