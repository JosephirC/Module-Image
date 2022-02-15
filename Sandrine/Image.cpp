#include "Image.h"
#include <stdlib.h>
#include <cassert>
#include <string>
#include <fstream>
#include <iostream>
#include <./LIFAP4/LIFAP4_TD/SDL2_image-2.0.5/i686-w64-mingw32/include/SDL2/SDL_image.h>

using namespace std;


Image::Image()
{
    dimx=0;
    dimy=0;
    tab=NULL;
    cout<<"default"<<endl;
}

Image::Image(const int dimensionX, const int dimensionY)
{
    dimx=dimensionX;
    dimy=dimensionY;
    tab= new Pixel[dimx*dimy];
    cout<<"perso"<<endl;
}


Image::~Image()
{
    delete[] tab;
    dimx=0;
    dimy=0;
    cout<<"detruit"<<endl;
}

Pixel Image::getPix(const int x, const int y) const
{
    assert(x<=dimx);
    assert(y<=dimy);
    cout<<"c'est bon"<<endl;
    return tab[y*dimx+x];
}

void Image::setPix (const int x, const int y, const Pixel couleur)
{
    assert(x<=dimx);
    assert(y<=dimy);
    cout<<"c'est bon"<<endl;
    tab[y*dimx+x]=couleur;
}

void Image::dessinerRectangle (const int Xmin, const int Ymin, const int Xmax, const int Ymax, const Pixel couleur)
{
    for(int i=Ymin*dimx+Xmin; i<=Ymax*dimx+Xmax; i++)
    {
        tab[i]=couleur;
    }
    cout<<"rectangle"<<endl;
}

void Image::effacer (Pixel couleur)
{
    dessinerRectangle(0, 0, dimx-1, dimy-1, couleur);
    cout<<"effacer"<<endl;
}

void Image::testRegression ()
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

void Image::sauver(const string & filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel pix = getPix(x++,y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	char r,g,b;
	string mot;
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);
	if (tab != NULL) delete [] tab;
	tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            fichier >> r >> b >> g;
            getPix(x,y).setRouge(r);
            getPix(x,y).setVert(g);
            getPix(x,y).setBleu(b);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

/*void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}*/


void Image::afficherInit();
{
    if(SDL_Init(SDL_Init_Video)<0)
    {
        cout<<"Erreur pendant l'initialisation de la SDL : "<<SDL_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }

       /**< @brief Création de la fenêtre*/
       window=SDL_CreateWindow("image", SDL_WindowPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINSIZE, WINSIZE, SDL_WINDOW_SHOWN);
       if(window==NULL)
       {
            cout<<"Erreur pendant la creation de la fenetre : " <<SDL_GetError()<<endl;
            SDL_Quit();
            exit(1);
       }
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}

void Image::afficherBoucle()
{

}

void Image::afficherDetruit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit;
}

void Image::afficher()
{

}


