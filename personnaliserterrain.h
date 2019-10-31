#ifndef PERSONNALISERTERRAIN_H
#define PERSONNALISERTERRAIN_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "terrain.h"



class personnaliserTerrain : public QDialog
{
public:
    personnaliserTerrain(QWidget *parent=nullptr);
    terrain terr()const;

private:
    terrain d_terr;

    QLineEdit*editLigne;
    QLineEdit*editColonne;

private slots:
    void onValider();
};

#endif // PERSONNALISERTERRAIN_H
