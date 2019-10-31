#ifndef TERRAIN_H
#define TERRAIN_H

#include "joueur.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <vector>


class terrain
{
    public:
     terrain();
     terrain(int nbdebris, int nbrobotfirstG, int nbrobotsecondG, int taille1, int taille2);
     int nbColonne()const;
     int nbLigne()const;
     void lireTerrain(const std::string&nomFichier);
     void sauverTerrain(const std::string&nomFichier);
     void changerTailleGrille(int taille1, int taille2);
     void InitialisationGrille();
     void afficheGrille(); // fonction test

    private :
     int d_nbdebris;
    // joueur d_joueur;
     int d_nbrobotFirstG;
     int d_nbrobotSecondG;
     int d_taille1;
     int d_taille2;
     std::vector<std::vector<int>> d_grille; // 0 = vide, 1 = joueur, 2 = robot1G, 3 = robot2G, 4 = debris




};

#endif // TERRAIN_H
