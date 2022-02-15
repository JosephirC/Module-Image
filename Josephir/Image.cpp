#include "Image.h"
#include <stdlib.h>
#include <cassert>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Image::Image () {
    dimx = 0;
    dimy = 0;
    tab = NULL; 
    cout << "default" << endl;
}

Image::Image(int dimensionX, int dimensionY){
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel [dimx * dimy];
    cout << "personnalise" << endl;
        
}

Image::~Image(){
    delete [] tab;
    dimx = 0;
    dimy = 0;
    cout << "destruction" << endl;
}

Pixel Image::getPix(unsigned int x, unsigned int y)const {
    assert(x == dimx);
    assert(y == dimy);
    return tab [y * dimx + x];
}

void Image::setPix(unsigned int x, unsigned int y, Pixel couleur){
    assert(x == dimx);
    assert(y == dimy);
    tab[y * dimx + x] = couleur;
}

void Image::dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, Pixel couleur){
    //setPix(int x, int y, couleur);
    for (unsigned int i = (Ymin * dimx + Xmin); i <= (Ymax * dimx + Xmax); i++){
        tab[i] = couleur;
    }
    cout << "dessin de rectangle" << endl;
}

void Image::effacer(Pixel couleur){
    dessinerRectangle(0, 0, dimx-1, dimy-1, couleur); 
    cout << "rectangle effacé";
}

void Image::testRegression(){
     Image test (3, 3);
    Image test2;
    Pixel noir;
    Pixel blanc (255, 255, 255);
    test.dessinerRectangle(0, 0, 2, 2, noir);
    test.setPix(1,1,blanc);
    test.setPix(1,0,test.getPix(1,1));
    cout<<"regression ";
}

void Image::sauver(const string & filename) const {
    ofstream fichier;
    fichier.open(filename.c_str());
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

/*void Image::ouvrir(const string & filename) {
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

void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}*/

