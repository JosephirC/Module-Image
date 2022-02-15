#include "Pixel.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Pixel::Pixel () {
    r = 0;
    g = 0;
    b = 0;
}

Pixel::Pixel(int nr, int ng, int nb) {
    r = nr;
    g = ng;
    b = nb;
}

int Pixel::getRouge()const{
    return r;
}

int Pixel::getVert()const{
    return g;
}

int Pixel::getBleu()const{
    return b;
}

void Pixel::setRouge (int nr){
    r=nr;
}

void Pixel::setVert (int ng){
    g=ng;
}


void Pixel::setBleu (int nb){
    b=nb;
}
