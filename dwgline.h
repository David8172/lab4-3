#ifndef DWGLINE_H
#define DWGLINE_H

#include "dwgobject.h"

class DwgLine : public DwgObject
{
    Q_OBJECT
public:
    explicit DwgLine(QObject *parent = nullptr);
    ~DwgLine() ;


    // DwgObject interface
public:
    virtual void Draw(QPainter *painter);

private:
    QPointF mStartPt,mEndPt;


    // DwgObject interface
public:
    virtual void SetData(QPoint p1, QPoint p2);
};

#endif // DWGLINE_H
