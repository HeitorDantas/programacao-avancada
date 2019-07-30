#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <algorithm>
#include <QDebug>
#include <QString>


Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    valuesVec.resize(30);
    timeVec.resize(30);
}

void Plotter::paintEvent(QPaintEvent *e){
    //painter setup


    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(55,55,55));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(255,255,255));
    pen.setWidth(2);

    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawRect(0,0,width(),height());
    painter.translate(0,height());

    int x1,x2,y1,y2;
    x1 = 0;
    y1 = 0;



    for(unsigned int i=0;i<timeVec.size();i++){
        x2 = timeVec[i];
        y2 = valuesVec[i];
        painter.drawLine(x1,-y1,x2,-y2);
        x1 = x2;
        y1 = y2;
    }




}



void Plotter::receiveData(std::vector<int> value, std::vector<qint64> time)
{
    //normaliza

    int max_value = *std::max_element(value.begin(),value.end());
    qint64  max_time,t1,t2;
    t2 = time.back();
    t1 = time.front();
    max_time = t2- t1;
    double aux;

    for(auto it = value.begin();it != value.end(); it++){
        aux = *it;
        aux = aux/(float)max_value;
        aux = aux*height();
        *it = (int)aux;

    }

    qDebug() << " time "<<max_time;
    for(auto it = time.begin();it != time.end(); it++){
        aux = (double)(*it - t1);
       // qDebug() << "time front = " << t1;
        //qDebug() << "*it = " << *it;
        aux = aux/(float)max_time;
        aux = aux*width();
        *it = (qint64)aux;


    }

    valuesVec = value;
    timeVec = time;
    repaint();

}

