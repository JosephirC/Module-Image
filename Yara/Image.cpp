#include "Image.h"
#include <stdlib.h>
#include <iostream>
#include <cassert>

using namespace std;

Image::Image(){
    dimx = 0;
    dimy = 0;
    tab = NULL;
    cout<< "default"<<endl;
}

Image::Image(int dimensionX,int dimensionY){
    dimx=dimensionX;
    dimy=dimensionY;
    tab=new Pixel[dimx*dimy];
    cout<<"perso"<<endl;
}

Image::~Image()
{
    delete [] tab;
    dimx=0;
    dimy=0;
    cout<<"detruit"<<endl;
}

Pixel Image::getPix(const int x, const int y)const
{
    assert(x<=dimx);
    assert(y<=dimy);
    cout<<" c'est bon "<<endl;
    return tab[y*dimx+x];
}

void Image::setPix(const int x, const int y , Pixel couleur)
{
    assert(x<=dimx);
    assert(y<=dimy);
    tab[y*dimx+x]=couleur;
}

void Image::dessinerRectangle(const int Xmin , const int Ymin , const int Xmax , const int Ymax, const Pixel couleur)
{
    for (int i= (Ymin*dimx+Xmin) ; i<=Ymax*dimx+Xmax ; i++)
    {
        tab[i]=couleur;
    }
    cout<<"rectangle"<<endl;
}

void Image::effacer (Pixel couleur)
{
    dessinerRectangle(0,0,dimx-1,dimy-1,couleur);
    cout<<"effacer"<<endl;
}

void Image::testRegression()
{
    Image test(3,3);
    Image test2;
    Pixel noir;
    Pixel blanc(255,255,255);
    test.dessinerRectangle(0,0,2,2,noir);
    test.setPix(1,1,blanc);
    test.setPix(1,0,test.getPix(1,1));
    cout<<"regression"<<endl;
}
