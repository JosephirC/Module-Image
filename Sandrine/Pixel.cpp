
class Pixel{

 private :

   int r,g,b; /**< @param les composantes du pixel, unsigned char en C++*/

 public :

   /**< @brief  Constructeur par défaut de la classe: initialise le pixel à  la couleur noire*/
    Pixel();

   /**< @brief  Constructeur de la classe: initialise r,g,b avec les paramètres*/
    Pixel(int nr, int ng, int nb);

   /**< @brief  Accesseur : récupère la composante rouge du pixel*/
    int getRouge ()const; /**< @param  entier*/

   /**< @brief  Accesseur : récupère la composante verte du pixel*/
    int getVert ()const; /**< @param entier*/

   /**< @brief  Accesseur : récupère la composante bleue du pixel*/
    int getBleu ()const; /**< @param entier*/

   /**< @brief  Mutateur : modifie la composante rouge du pixel*/
    void setRouge (int nr);

   /**< @brief  Mutateur : modifie la composante verte du pixel*/
    void setVert (int ng);

   /**< @brief  Mutateur : modifie la composante bleue du pixel*/
    void setBleu (int nb);

};

