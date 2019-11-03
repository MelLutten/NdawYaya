#include "grille.h"


grille::grille(terrain&t,QWidget *parent):QWidget{parent},d_terrain{t}{


}




void grille::paintEvent(QPaintEvent *e)
{

    QPainter painter(this);
    int left = 0;
    int top = 0;
    int width = 40;
    int height = 40;


    QBrush brush1("#242424", Qt::SolidPattern);
    QBrush brush2("#2F2F2F", Qt::SolidPattern);
    QPen pen1("#242424");
    QPen pen2("#2F2F2F");


    for(int i=0;i<d_terrain.nbLigne();++i){
        for(int j=0;j<d_terrain.nbColonne();++j){

            QRect r1(left+61, top, width, height);

            if(j%2==0){

               painter.setPen(pen1);
               painter.fillRect(r1, brush1);

            }
            else{
                 painter.setPen(pen2);
                 painter.fillRect(r1, brush2);
           }
            if(d_terrain.Joueur().positionJoueur().numLigne()==i && d_terrain.Joueur().positionJoueur().numColonne()==j){

                painter.drawImage(r1,QImage("/Users/Neron/Desktop/joueur.png"));

            }

            painter.drawRect(r1);
            left+=51;
       }

        left = 0;
        top +=51;
        swap(brush1,brush2);
        swap(pen1,pen2);

   }


}
