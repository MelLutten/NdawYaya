#include "grille.h"


grille::grille(terrain&t,QWidget *parent):QWidget{parent},d_terrain{t}{


}




void grille::paintEvent(QPaintEvent *e)
{

    QPainter painter(this);
    int left = 0;
    int top = 0;
    int width = 100;
    int height = 100;

    QBrush brush1(Qt::black, Qt::SolidPattern);
    QBrush brush2(Qt::white, Qt::SolidPattern);

    for(int i=0;i<d_terrain.nbLigne();++i){
        for(int j=0;j<d_terrain.nbColonne();++j){

            QRect r1(left+101, top, width, height);

            if(j%2==0){
                 painter.fillRect(r1, brush1);
            }else{
                 painter.fillRect(r1, brush2);
           }
            if(d_terrain.grille()[i][j]==1){

                painter.fillRect(r1,joueur);

            }


            painter.drawRect(r1);
            left+=101;
       }
        left = 0;
        top +=101;
        QBrush brush3 = brush1;
        brush1 = brush2;
        brush2 = brush3;

   }

}
