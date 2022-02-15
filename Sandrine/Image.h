#include "Pixel.h"
#include <string>
using namespace std;


class Image{

 private :

    Pixel *tab;             /**< @param   le tableau 1D de pixel*/
    int dimx, dimy;       /**< @param  les dimensions de l'image*/

 public :

   /**< @brief  Constructeur par défaut de la classe: initialise dimx et dimy Ã  0
    ce constructeur n'alloue pas de pixel */
    Image();

   /**< @brief  Constructeur de la classe: initialise dimx et dimy (aprÃ¨s vÃ©rification)
    puis alloue le tableau de pixel dans le tas (image noire)*/
    Image(int dimensionX, int dimensionY);

   /**< @brief  Destructeur de la classe: dÃ©allocation de la mÃ©moire du tableau de pixels
    et mise Ã  jour des champs dimx et dimy Ã  0*/
    ~Image();

   /**< @brief  Accesseur : récupÃ¨re le pixel original de coordonnÃ©es (x,y) en vÃ©rifiant leur validitÃ©
    la formule pour passer d'un tab 2D Ã  un tab 1D est tab[y*dimx+x]*/
    Pixel getPix (int x, int y) const; //'Pixel' (l'original, pas une copie)

   /**< @brief   Mutateur : modifie le pixel de coordonnÃ©es (x,y)*/
    void setPix (int x, int y, Pixel couleur);

   /**< @brief  Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramÃ¨tre compris)*/
    void dessinerRectangle (int Xmin, int Ymin, int Xmax, int Ymax, Pixel couleur);

   /**< @brief  Efface l'image en la remplissant de la couleur en paramÃ¨tre
    (en appelant dessinerRectangle avec le bon rectangle)*/
    void effacer (Pixel couleur);

   /**< @brief  Effectue une sÃ©rie de tests vÃ©rifiant que le module fonctionne et
    que les donnÃ©es membres de l'objet sont conformes*/
    void testRegression ();

    void sauver(const string & filename) const;

    void ouvrir(const string & filename);

    void afficherConsole();

    void afficher ();

};

