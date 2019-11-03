#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include <QMainWindow>
#include <QGridLayout>
#include <QObject>
#include <QPushButton>
#include <QDialog>
#include "grille.h"
#include "personnaliserterrain.h"


class fenetre : public QMainWindow
{
    Q_OBJECT
public:
    fenetre(terrain&t);
private:
    terrain d_t;
    QMainWindow*d_win;
    grille*d_grille;
    personnaliserTerrain*d_p;
    void vueCreer(terrain&t);


private slots :
    void OnDifficile();
    void OnFacile();
    void OnNormal();
    void OnPerso();
    void OnHaut();
    void OnBas();
    void OnDroite();
    void OnGauche();
};

#endif // FENETRE_H
