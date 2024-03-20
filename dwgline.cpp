#include "dwgline.h"

DwgLine::DwgLine(QObject *parent)
    : DwgObject{parent}
{

}

DwgLine::~DwgLine()
{

}


void DwgLine::Draw(QPainter *painter)
{
    painter->drawLine(mStartPt,mEndPt);
}


void DwgLine::SetData(QPoint p1, QPoint p2)
{
    mStartPt = p1;
    mEndPt = p2;
}


void DwgLine::Select(QPoint pt)
{
}
