#include "fenetre.h"

fenetre::fenetre(terrain&t):d_t{t}, d_win{this}
{
    vueCreer(t);

}



void fenetre::vueCreer(terrain&t){

    setWindowTitle("HI ROBOTS");

    //Terrain
    d_grille = new grille{t};

    //Titre
    auto label = new QLabel{"HI ROBOTS"};
    label->setFixedSize(maximumWidth(),60);
    label->setStyleSheet("QLabel { background-color : #2F2F2F; color : #2B71D9; font-size:20px; }");
    label->setAlignment(Qt::AlignCenter);

    //Boutons niveau
    auto layoutbouton = new QHBoxLayout{};
    auto facile = new QPushButton{"FACILE"};
    auto normal = new QPushButton{"NORMAL"};
    auto difficile = new QPushButton{"DIFFICILE"};
    auto personnalise = new QPushButton{"PERSONNALISE"};
    facile->setStyleSheet("QPushButton{ background-color:#242424;font-size:15px;height:30px;}");
    normal->setStyleSheet("QPushButton{ background-color:#242424;font-size:15px;height:30px;}");
    difficile->setStyleSheet("QPushButton{ background-color:#242424;font-size:15px;height:30px;}");
    personnalise->setStyleSheet("QPushButton{ background-color:#242424;font-size:15px;height:30px;}");
    layoutbouton->addWidget(facile);
    layoutbouton->addWidget(normal);
    layoutbouton->addWidget(difficile);
    layoutbouton->addWidget(personnalise);

     connect(difficile,&QPushButton::clicked,this,&fenetre::OnDifficile);
     connect(normal,&QPushButton::clicked,this,&fenetre::OnNormal);
     connect(facile,&QPushButton::clicked,this,&fenetre::OnFacile);

     //Dialogue personnalisé
     d_p = new personnaliserTerrain{};

     connect(personnalise,&QPushButton::clicked,this,&fenetre::OnPerso);


    //Principale
    auto layout = new QVBoxLayout{};
    layout->addWidget(label,Qt::AlignCenter);
    layout->addLayout(layoutbouton);
    layout->addWidget(d_grille,Qt::AlignCenter);




    auto Wid = new QWidget;
    Wid->setLayout(layout);


    setCentralWidget(Wid);


}



void fenetre::OnDifficile(){
    d_t.changerTailleGrille(8,8);
    d_t.changerNb(3,3,3);
    d_t.InitialisationGrille(3,3,3);
    d_t.afficheGrille(); //Test : affichage console
    vueCreer(d_t);
}

void fenetre::OnNormal(){
    d_t.changerTailleGrille(5,5);
    d_t.changerNb(2,2,2);
    d_t.InitialisationGrille(2,2,2);
    d_t.afficheGrille(); //Test : affichage console
    vueCreer(d_t);
}

void fenetre::OnFacile(){
    d_t.changerTailleGrille(5,5);
    d_t.changerNb(1,1,1);
    d_t.InitialisationGrille(1,1,1);
    d_t.afficheGrille(); //Test affichage console
    vueCreer(d_t);
}

void fenetre::OnPerso(){

    d_p->exec();
    d_t = d_p->terr();
    d_t.afficheGrille(); //Test affichage console

    if(d_t.terrainOk()){
         vueCreer(d_t);
    }

}




