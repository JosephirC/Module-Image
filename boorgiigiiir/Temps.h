#ifndef _TEMPS_H
#define _TEMPS_H

#include "Ingredrient.h"
#include <string>
#include <time.h>
#include <iostream>

using namespace  std;

class Temps{

    private :

        clock_t t1;
        int temps;

    public :

        //Temps(); // useless, ps de sens

        Temps(temps); // Dans le .cpp on fait temps_donne = temps 
        // on fait appelle a la fonction clock(), on la stocque dans t1, 

        ~Temps();

        bool tempsAtteint(); // temps_donne - (t2 - t1) avec t2 le temps qui se calcule au debut de la partie

        //je fais un appelle a clock, je fais la diff par rapport au t1 , pour savoir le temps ecoule, et puis je fais temps - t1 
        //on divise pour enlever les decimales puis on fait la diff
        //tempsatteint appelle tempsRestant
        //vrai si <0


        int tempsRestant();
        // temps - (t2 - t1)
    


        


};

#endif