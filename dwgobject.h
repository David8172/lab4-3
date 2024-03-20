#ifndef DWGOBJECT_H
#define DWGOBJECT_H

#include <QObject>
#include <QColor>
#include <QPainter>

class DwgObject : public QObject
{
    Q_OBJECT
public:
    explicit DwgObject(QObject *parent = nullptr);
    ~DwgObject() ;

    virtual void Draw(QPainter * painter) = 0;
    virtual void SetData(QPoint p1,QPoint p2) = 0;
    virtual void Select(QPoint pt) = 0  ;

    bool mSelected = false;

private:
    int mLineWidth =  0;
    QColor mColor = Qt::black;

signals:

};

#endif // DWGOBJECT_H
