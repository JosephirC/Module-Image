#include "Pixel.h"
#include <iostream>

using namespace std;

Pixel::Pixel()
{
    r=0;
    g=0;
    b=0;
    cout<<"pix"<<endl;
}

Pixel::Pixel(const int nr, const int ng, const int nb)
{
    r=nr;
    g=ng;
    b=nb;
    cout<<"pixel"<<endl;
}

int Pixel::getRouge ()const
{
    return r;
}

int Pixel::getVert ()const
{
    return g;
}

int Pixel::getBleu ()const
{
    return b;
}

void Pixel::setRouge (int nr)
{
    r=nr;
}

void Pixel::setVert (int ng)
{
    g=ng;
}

void Pixel::setBleu (int nb)
{
    b=nb;
}






