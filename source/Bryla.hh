#ifndef BRYLA_HH
#define BRYLA_HH
#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include <vector>
#include <cmath>
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

/*!
 * \brief Modeluje pojecie klasy bazowej Bryla
 *
 */



class Bryla
{

protected:
    vector<vector<Wektor3D>> krzywa;
    vector<vector<Wektor3D>> kop_krzywa;
    Wektor3D przes;
    double kat;
    double kat_sm;
    double kat_wz;
    Macierz3x3 Ma;
    Macierz3x3 MoX;
    Macierz3x3 MoY;
    std::shared_ptr<drawNS::Draw3DAPI> &api;
    Wektor3D srodek;
    int id;
    static int figury;
    public:
/*!
* \brief konstruktor obiektow klasy Bryla

*/
Wektor3D get_srodek()
{
    return przes;
}
    Wektor3D set_srodek(Wektor3D srodek)
    {
        this->srodek=srodek;
    }
    
    
/*!
* \brief metoda odpowiadajaca za zmiane polozenia

*/


   Bryla(std::shared_ptr<drawNS::Draw3DAPI> &api):api(api){figury++;}
   

static int pokazfigury(){return figury++;};

    ~Bryla()
    {figury--;}



 void przesun(Wektor3D przesuniecie);
   

    

Wektor3D get_przsuniecie(){
    return przes;
}
    Wektor3D get_wirz(int i,int j){return kop_krzywa[i][j];}

/*!
* \brief  metoda odpowiadajaca za ruch w plaszczyznie

*/
   virtual void ruch(double przesuniecie, double kat_obr);
   
/*!
* \brief  metoda odpowiadajaca za ruch w pionie

*/
    void pion(double przesuniecie, double kat_obr);
   


  void osx(double przesuniecie, double kat_obr);
   

/*!
* \brief macierz obrotu

*/



    void macierz();
   
    void macierzY();
   
     void macierzX();
   

/*!
* \brief  metoda odpowiadajaca za rysowanie obiektow klasy bryla

*/

    void rysuj();
    




};
#endif