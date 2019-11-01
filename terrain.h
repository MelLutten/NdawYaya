#include "joueur.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <vector>


class terrain
{
    public:
     terrain();
     terrain(int nbdebris, int nbrobotfirstG, int nbrobotsecondG, int nbligne, int nbcolonne);

     int nbColonne()const;
     int nbLigne()const;
     int nbDebris()const;
     int nbRobot1G()const;
     int nbRobot2G()const;
     std::vector<std::vector<int>> grille()const;

     void lireTerrain(const std::string&nomFichier);
     void sauverTerrain(const std::string&nomFichier);
     void changerTailleGrille(int nbligne, int nbcolonne);
     void changerNb(int nbdebris,int nbRobot1G,int nbRobot2G);
     void InitialisationGrille(int nbdebris, int nbRobot1G, int nbRobot2G);
     bool terrainOk();
     void afficheGrille(); // fonction test

    private :
     int d_nbdebris;
    // joueur d_joueur;
     int d_nbrobotFirstG;
     int d_nbrobotSecondG;
     int d_nbligne;
     int d_nbcolonne;
     std::vector<std::vector<int>> d_grille; // 0 = vide, 1 = joueur, 2 = robot1G, 3 = robot2G, 4 = debris




};

#endif // TERRAIN_H
