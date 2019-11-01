#ifndef PERSONNALISERTERRAIN_H
#define PERSONNALISERTERRAIN_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
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
    QLineEdit*editDebris;
    QLineEdit*editRobot1G;
    QLineEdit*editRobot2G;

private slots:
    void onValider();
};

#endif // PERSONNALISERTERRAIN_H
