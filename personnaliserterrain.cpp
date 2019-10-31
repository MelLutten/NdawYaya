#include "personnaliserterrain.h"

personnaliserTerrain::personnaliserTerrain(QWidget*parent):QDialog{parent}
{

    //Boutons
    auto closeBtn = new QPushButton("Annuler");
    auto ok = new QPushButton("Valider");
    auto boutons = new QHBoxLayout{};
    boutons->addWidget(ok);
    boutons->addWidget(closeBtn);

    connect(closeBtn, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ok,&QPushButton::clicked,this,&personnaliserTerrain::onValider);


    //Nb Ligne
    auto labelLigne = new QLabel{"Nombre de ligne : "};
    editLigne = new QLineEdit{};
    auto nbLigne = new QHBoxLayout{};
    nbLigne->addWidget(labelLigne);
    nbLigne->addWidget(editLigne);

    //Nb Colonne
    auto labelColonne = new QLabel{"Nombre de colonne : "};
    editColonne = new QLineEdit{};
    auto nbColonne = new QHBoxLayout{};
    nbColonne->addWidget(labelColonne);
    nbColonne->addWidget(editColonne);

    //Nb Debris
    auto labelDebris = new QLabel{"Nombre de débris : "};
    editDebris = new QLineEdit{};
    auto nbDebris = new QHBoxLayout{};
    nbDebris->addWidget(labelDebris);
    nbDebris->addWidget(editDebris);

    //Nb RobotFirstG
    auto labelRobot1G = new QLabel{"Nombre de robot 1ere G : "};
    editRobot1G = new QLineEdit{};
    auto nbRobot1G = new QHBoxLayout{};
    nbRobot1G->addWidget(labelRobot1G);
    nbRobot1G->addWidget(editRobot1G);

    //Nb RobotSecondG
    auto labelRobot2G = new QLabel{"Nombre de robot 2nd G : "};
    editRobot2G = new QLineEdit{};
    auto nbRobot2G = new QHBoxLayout{};
    nbRobot2G->addWidget(labelRobot2G);
    nbRobot2G->addWidget(editRobot2G);


    //Principal
    auto layoutPrinc = new QVBoxLayout{};
    layoutPrinc->addLayout(nbLigne);
    layoutPrinc->addLayout(nbColonne);
    layoutPrinc->addLayout(nbDebris);
    layoutPrinc->addLayout(nbRobot1G);
    layoutPrinc->addLayout(nbRobot2G);
    layoutPrinc->addLayout(boutons);



    setLayout(layoutPrinc);
}

terrain personnaliserTerrain::terr()const{
    return d_terr;
}

void personnaliserTerrain::onValider(){

    QString tl = editLigne->text();
    int nbligne = tl.toInt();
    QString tc = editColonne->text();
    int nbcolonne = tc.toInt();
    QString td = editDebris->text();
    int nbdebris = td.toInt();
    QString tr1 = editRobot1G->text();
    int nbrobot1G = tr1.toInt();
    QString tr2 = editRobot2G->text();
    int nbrobot2G = tr2.toInt();
    d_terr.changerTailleGrille(nbcolonne,nbligne);
    d_terr.InitialisationGrille(nbdebris,nbrobot1G,nbrobot2G);
    close();


}
