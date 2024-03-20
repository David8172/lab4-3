#ifndef DWGCIRCLE_H
#define DWGCIRCLE_H

#include "dwgobject.h"

class DwgCircle : public DwgObject
{
    Q_OBJECT
public:
    explicit DwgCircle(QObject *parent = nullptr);

private:
    QPointF mCenPt;
    qreal mRad;

    // DwgObject interface
public:
    virtual void Draw(QPainter *painter);
    virtual void SetData(QPoint p1, QPoint p2);
};

#endif // DWGCIRCLE_H
