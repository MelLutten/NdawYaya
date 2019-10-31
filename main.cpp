#include "grille.h"
#include <QApplication>
#include "fenetre.h"

int main(int argc, char *argv[])
{
    //joueur j;
    terrain t(1,2,2,4,4);

    QApplication app{argc,argv};
    fenetre f(t);
    f.show();
    app.exec();
}
