#include "terrain.h"

terrain::terrain():d_nbdebris{0},d_nbrobotFirstG{0},d_nbrobotSecondG{0},d_taille1{0},d_taille2{0}
{}

terrain::terrain(int nbdebris,int nbrobotfirstG, int nbrobotsecondG, int taille1, int taille2):d_nbdebris{nbdebris},d_nbrobotFirstG{nbrobotfirstG},d_nbrobotSecondG{nbrobotsecondG},d_taille1{taille1},d_taille2{taille2}
{
    if(terrainOk()){
         d_grille.resize(static_cast<unsigned>(d_taille1), std::vector<int>(static_cast<unsigned>(d_taille2)));
         InitialisationGrille(d_nbdebris,d_nbrobotFirstG,d_nbrobotSecondG);
         sauverTerrain("/Users/Neron/Desktop/premiereSauvegarde.txt");
    }
}

void terrain::sauverTerrain(const std::string&nomFichier){

    std::ofstream f (nomFichier, std::ofstream::out);
    f << d_nbdebris << "," << d_nbrobotFirstG << "," << d_nbrobotSecondG << "," << d_taille1 << "," << d_taille2;
    f.close();

}

int terrain::nbColonne()const{
    return d_taille1;
}

int terrain::nbLigne()const{
    return d_taille2;
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

std::vector<std::vector<int>> terrain::grille()const{
    return d_grille;
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
 d_grille.resize(static_cast<unsigned>(d_taille1), std::vector<int>(static_cast<unsigned>(d_taille2)));



}

//Problème avec une valeur à 0 quand il la génère en premier, à corriger
void terrain::InitialisationGrille(int nbdebris, int nbRobot1G, int nbRobot2G){



    std::vector<int> V(9);
    V = { 0,0,0,0,0,0,1,2,3,4 };//0 permettent de mieux espacer le joueurs/robots/débris

    int compteurJoueur = 0;
    int compteurRobot1G = 0;
    int compteurRobot2G = 0;
    int compteurDebris = 0;
    int compteurZero = 0;

    srand(time(NULL));

    for(int i=0;i<d_taille2;++i){
        for(int j=0;j<d_taille1;++j){

            int indice = rand()%static_cast<int>(V.size()); //génère un indice aléatoire 
            int nbalea = V[static_cast<unsigned>(indice)]; //prend valeur de l'indice alétaoire

            d_grille[static_cast<unsigned>(i)][static_cast<unsigned>(j)] = nbalea;

            if(nbalea==0){++compteurZero;}
            if(nbalea==1){++compteurJoueur;}
            if(nbalea==2){++compteurRobot1G;}
            if(nbalea==3){++compteurRobot2G;}
            if(nbalea==4){++compteurDebris;}

            //suppression des cases contenant 0 dans le tableau V (case vide)
            if(compteurZero==(d_taille1*d_taille2)-(nbdebris+nbRobot1G+nbRobot2G+1)){

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


                 compteurZero = ((d_taille1*d_taille2)-(nbdebris+nbRobot1G+nbRobot2G+1))+1;
            }

            //suppression de la case contenant 2 dans le tableau V (Robot1G)
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
            
            //suppression de la case contenant 3 dans le tableau V (Robot2G)
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
            
            //suppression de la case contenant 4 dans le tableau V (Debris)
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
            
            //suppression de la case contenant 1 dans le tableau V (Joueur)
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

bool terrain::terrainOk(){

    if(d_taille1*d_taille2>d_nbdebris+d_nbrobotFirstG+d_nbrobotSecondG+1){
        return true;
    }else{
        return false;
    }


}





//Fonction test
void terrain::afficheGrille(){

    if(terrainOk()){
        for(int i=0;i<d_taille2;++i){
            for(int j=0;j<d_taille1;++j){
                std::cout<<d_grille[static_cast<unsigned>(i)][static_cast<unsigned>(j)]<<"|";
            }
            std::cout<<std::endl;
        }
    }else{
        std::cout<<"T'as fait de la merde, recommence";
    }

}

 
