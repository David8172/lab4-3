#include "dwgcircle.h"
#include <QtMath>

DwgCircle::DwgCircle(QObject *parent)
    : DwgObject{parent}
{

}

void DwgCircle::Draw(QPainter *painter)
{
    if(mSelected)
        painter->setPen(Qt::red);
    painter->drawEllipse(mCenPt,mRad,mRad);
    painter->setPen(Qt::black);
}

void DwgCircle::SetData(QPoint p1, QPoint p2)
{
    mCenPt = p1;
    mRad = sqrt((p1.x()-p2.x())*(p1.x()-p2.x())+
                (p1.y()-p2.y())*(p1.y()-p2.y()));

}


void DwgCircle::Select(QPoint pt)
{
    qreal dist = sqrt((pt.x()-mCenPt.x())*(pt.x()-mCenPt.x())+
                      (pt.y()-mCenPt.y())*(pt.y()-mCenPt.y()));
    if(fabs(dist-mRad) < 3)
        mSelected = true;
}
