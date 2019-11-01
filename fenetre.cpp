#include "fenetre.h"

fenetre::fenetre(terrain&t):d_t{t}, d_win{this}
{
    vueCreer(t);

}



void fenetre::vueCreer(terrain&t){




    setWindowTitle("HI ROBOTS");

    setStyleSheet("QMainWindow{background:#353535;}");

    //Terrain
    d_grille = new grille{t};
    d_grille->setFixedHeight(550);

    //Titre
    auto label = new QLabel{this};
    QPixmap *logo = new QPixmap ("/Users/Neron/Desktop/hirobot.png" );
    label->setPixmap(*logo);


    label->setFixedSize(maximumWidth(),150);
    label->setAlignment(Qt::AlignCenter);

    //Boutons niveau
    auto layoutbouton = new QHBoxLayout{};
    auto facile = new QPushButton{"FACILE"};
    auto normal = new QPushButton{"NORMAL"};
    auto difficile = new QPushButton{"DIFFICILE"};
    auto personnalise = new QPushButton{"PERSONNALISE"};
    facile->setStyleSheet("QPushButton{ background-color:#242424;font-size:11px;height:30px;color:#6C6C6C;}");
    normal->setStyleSheet("QPushButton{ background-color:#242424;font-size:11px;height:30px;color:#6C6C6C;}");
    difficile->setStyleSheet("QPushButton{ background-color:#242424;font-size:11px;height:30px;color:#6C6C6C;}");
    personnalise->setStyleSheet("QPushButton{ background-color:#242424;font-size:11px;height:30px;color:#6C6C6C;}");
    layoutbouton->addWidget(facile);
    layoutbouton->addWidget(normal);
    layoutbouton->addWidget(difficile);
    layoutbouton->addWidget(personnalise);


     connect(difficile,&QPushButton::clicked,this,&fenetre::OnDifficile);
     connect(normal,&QPushButton::clicked,this,&fenetre::OnNormal);
     connect(facile,&QPushButton::clicked,this,&fenetre::OnFacile);

     //Copyright
     auto layoutcopy = new QLabel{"© Faculté des Sciences et Techniques de Mulhouse <br> Kolokolnikova - Luttenschlager - Moins - Ndwa"};
     layoutcopy->setAlignment(Qt::AlignCenter);




     //Dialogue personnalisé
     d_p = new personnaliserTerrain{};

     connect(personnalise,&QPushButton::clicked,this,&fenetre::OnPerso);


    //Principale
    auto layout = new QVBoxLayout{};
    layout->addWidget(label,Qt::AlignCenter);
    layout->addLayout(layoutbouton);
    layout->addWidget(d_grille,Qt::AlignCenter);
    layout->addWidget(layoutcopy,Qt::AlignCenter);




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
    vueCreer(d_t);



}



