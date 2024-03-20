#include "dwgcircle.h"
#include <QtMath>

DwgCircle::DwgCircle(QObject *parent)
    : DwgObject{parent}
{

}

void DwgCircle::Draw(QPainter *painter)
{
    painter->drawEllipse(mCenPt,mRad,mRad);
}

void DwgCircle::SetData(QPoint p1, QPoint p2)
{
    mCenPt = p1;
    mRad = sqrt((p1.x()-p2.x())*(p1.x()-p2.x())+
                (p1.y()-p2.y())*(p1.y()-p2.y()));

}
