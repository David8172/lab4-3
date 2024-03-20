#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dwgobject.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum DrawType {
    DNone,
    DLine,
    DCircle,
    DRectangle
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    DrawType mCurDrawType = DNone;

    QVector<DwgObject *> mMainVec;

private slots:
    void on_actionLine_triggered();

    void on_actionCircle_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
