#include "terrain.h"

terrain::terrain(){

}

terrain::terrain(int nbdebris,int nbrobotfirstG, int nbrobotsecondG, int taille1, int taille2):d_nbdebris{nbdebris},d_nbrobotFirstG{nbrobotfirstG},d_nbrobotSecondG{nbrobotsecondG},d_taille1{taille1},d_taille2{taille2}
{
    sauverTerrain("premiereSauvegarde.txt");
}

void terrain::sauverTerrain(const std::string&nomFichier){

    std::ofstream f (nomFichier, std::ofstream::out);
    f << d_nbdebris << ","<<d_nbrobotFirstG<<","<<d_nbrobotSecondG<<","<<d_taille1<<","<<d_taille2;
    f.close();

}

int terrain::taille1()const{
    return d_taille1;
}

int terrain::taille2()const{
    return d_taille2;
}

void terrain::lireTerrain(const std::string&nomFichier)
{
     std::ifstream f(nomFichier);
     char c;
     f >> d_nbdebris >> c >> d_nbrobotFirstG >> c >> d_nbrobotSecondG >> c >> d_taille1 >> c >> d_taille2;
}

void terrain::changerTailleGrille (int taille1, int taille2){

 d_taille1 = taille1;
 d_taille2 = taille2;

}
