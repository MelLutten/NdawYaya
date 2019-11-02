#include "terrain.h"

terrain::terrain():d_nbdebris{0},d_joueur{},d_nbrobotFirstG{0},d_nbrobotSecondG{0},d_nbligne{0},d_nbcolonne{0}
{}

terrain::terrain(int nbdebris,int nbrobotfirstG, int nbrobotsecondG, int nbligne, int nbcolonne, joueur&j):d_nbdebris{nbdebris},d_joueur{j},d_nbrobotFirstG{nbrobotfirstG},d_nbrobotSecondG{nbrobotsecondG},d_nbligne{nbligne},d_nbcolonne{nbcolonne}
{
    if(terrainOk()){

         d_robot1G.resize(static_cast<unsigned>(nbrobotfirstG));
         d_robot2G.resize(static_cast<unsigned>(nbrobotsecondG));

         d_grille.resize(static_cast<unsigned>(d_nbligne), std::vector<int>(static_cast<unsigned>(d_nbcolonne)));
         InitialisationGrille(d_nbdebris,d_nbrobotFirstG,d_nbrobotSecondG);
         sauverTerrain("/Users/Neron/Desktop/premiereSauvegarde.txt");

    }
}

void terrain::sauverTerrain(const std::string&nomFichier){

    std::ofstream f (nomFichier, std::ofstream::out);
    f << d_nbdebris << "," << d_nbrobotFirstG << "," << d_nbrobotSecondG << "," << d_nbligne << "," << d_nbcolonne;
    f.close();

}

int terrain::nbColonne()const{
    return d_nbcolonne;
}

int terrain::nbLigne()const{
    return d_nbligne;
}

int terrain::nbDebris()const{
    return d_nbdebris;

}

int terrain::nbRobot1G()const{
    return d_nbrobotFirstG;
}

int terrain::nbRobot2G()const{
    return d_nbrobotSecondG;
}

joueur terrain::Joueur(){
    return d_joueur;
}

std::vector<std::vector<int>> terrain::grille()const{
    return d_grille;
}


void terrain::lireTerrain(const std::string&nomFichier)
{
    std::ifstream f(nomFichier);
    char c;
    f >> d_nbdebris >> c >> d_nbrobotFirstG >> c >> d_nbrobotSecondG >> c >> d_nbligne >> c >> d_nbcolonne;
}

void terrain::changerTailleGrille (int nbligne, int nbcolonne){

 d_nbligne = nbligne;
 d_nbcolonne = nbcolonne;
 d_grille.resize(static_cast<unsigned>(d_nbligne), std::vector<int>(static_cast<unsigned>(d_nbcolonne)));



}

void terrain::changerNb(int nbdebris,int nbRobot1G,int nbRobot2G){

    d_nbdebris = nbdebris;
    d_nbrobotFirstG = nbRobot1G;
    d_nbrobotSecondG = nbRobot2G;
    d_robot1G.resize(static_cast<unsigned>(nbRobot1G));
    d_robot2G.resize(static_cast<unsigned>(nbRobot2G));

}

//Problème avec une valeur à 0 quand il la génère en premier, à corriger
void terrain::InitialisationGrille(int nbdebris, int nbRobot1G, int nbRobot2G){


    std::vector<int> V(9);
    V = { 0,0,0,0,0,0,1,2,3,4 };

    int compteurJoueur = 0;
    int compteurRobot1G = 0;
    int compteurRobot2G = 0;
    int compteurDebris = 0;
    int compteurZero = 0;

    srand(time(NULL));

    for(int i=0;i<d_nbligne;++i){
        for(int j=0;j<d_nbcolonne;++j){

            int indice = rand()%static_cast<int>(V.size());
            int nbalea = V[static_cast<unsigned>(indice)];

            d_grille[static_cast<unsigned>(i)][static_cast<unsigned>(j)] = nbalea;

            if(nbalea==0){++compteurZero;}
            if(nbalea==1){d_joueur.deplacerJoueur(j,i);++compteurJoueur;}
            if(nbalea==2){++compteurRobot1G;}
            if(nbalea==3){++compteurRobot2G;}
            if(nbalea==4){++compteurDebris;}


            if(compteurZero==(d_nbligne*d_nbcolonne)-(nbdebris+nbRobot1G+nbRobot2G+1)){

                int v = 6;
                while(v>0){

                    for(int g=0;g<static_cast<int>(V.size());++g){

                        if(V[static_cast<unsigned>(g)]==0){
                            for(int r=g;r<static_cast<int>(V.size());++r){

                                     V[static_cast<unsigned>(r)]=V[static_cast<unsigned>(r+1)];

                            }
                        }
                    }

                    V.resize(V.size()-1);
                    --v;
                }


                 compteurZero = ((d_nbligne*d_nbcolonne)-(nbdebris+nbRobot1G+nbRobot2G+1))+1;
            }


            if(compteurRobot1G==nbRobot1G){

                for(int g=0;g<static_cast<int>(V.size());++g){

                    if(V[static_cast<unsigned>(g)]==2){
                        for(int r=g;r<static_cast<int>(V.size());++r){
                            V[static_cast<unsigned>(r)]=V[static_cast<unsigned>(r+1)];

                        }
                    }
                }

                 V.resize(V.size()-1);
                 compteurRobot1G = nbRobot1G+1;
            }
            if(compteurRobot2G==nbRobot2G){

                for(int g=0;g<static_cast<int>(V.size());++g){

                    if(V[static_cast<unsigned>(g)]==3){
                        for(int r=g;r<static_cast<int>(V.size());++r){
                            V[static_cast<unsigned>(r)]=V[static_cast<unsigned>(r+1)];

                        }
                    }
                }

                 V.resize(V.size()-1);
                 compteurRobot2G = nbRobot2G+1;


            }
            if(compteurDebris==nbdebris){

                for(int g=0;g<static_cast<int>(V.size());++g){

                    if(V[static_cast<unsigned>(g)]==4){
                        for(int r=g;r<static_cast<int>(V.size());++r){
                            V[static_cast<unsigned>(r)]=V[static_cast<unsigned>(r+1)];

                        }
                    }
                }

                 V.resize(V.size()-1);
                 compteurDebris = nbdebris+1;

            }

            if(compteurJoueur==1){

                for(int g=0;g<static_cast<int>(V.size());++g){

                    if(V[static_cast<unsigned>(g)]==1){
                        for(int r=g;r<static_cast<int>(V.size());++r){
                            V[static_cast<unsigned>(r)]=V[static_cast<unsigned>(r+1)];

                        }
                    }
                }


                 V.resize(V.size()-1);
                 compteurJoueur = 2;

            }

        }
    }


}

void terrain::ChangerJoueur(joueur&j){
    d_joueur=j;
}


bool terrain::terrainOk(){

    if(d_nbligne*d_nbcolonne>d_nbdebris+d_nbrobotFirstG+d_nbrobotSecondG+1){
        return true;
    }else{
        return false;
    }


}





//Fonction test
void terrain::afficheGrille(){

    if(terrainOk()){
        for(int i=0;i<d_nbligne;++i){
            for(int j=0;j<d_nbcolonne;++j){
                std::cout<<d_grille[static_cast<unsigned>(i)][static_cast<unsigned>(j)]<<"|";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }else{
        std::cout<<"T'as fait de la merde, recommence";
   }

}

void terrain::afficherPositionJoueur(){
    std::cout<<d_joueur.positionJoueur().numLigne()<<";"<<d_joueur.positionJoueur().numColonne()<<std::endl;
}

 
