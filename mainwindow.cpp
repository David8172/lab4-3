#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include "dwgline.h"
#include "dwgcircle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLine_triggered()
{
    mCurDrawType = DLine;
}

QPoint temppt;
bool isFirst = true;


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(mCurDrawType & DLine)
    {
        if(isFirst)
        {
            temppt = event->pos();
            isFirst = false;
        }
        else
        {
            DwgLine *line = new DwgLine;
            line->SetData(temppt,event->pos());
            mMainVec.append(line);
            update();

            isFirst = true;
        }
    }
    if(mCurDrawType & DCircle)
    {
        if(isFirst)
        {
            temppt = event->pos();
            isFirst = false;
        }
        else
        {
            DwgCircle *circle = new DwgCircle;
            circle->SetData(temppt,event->pos());
            mMainVec.append(circle);
            update();

            isFirst = true;
        }

    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    for(auto i : mMainVec)
    {
        i->Draw(painter);
    }
    delete painter;
}

void MainWindow::on_actionCircle_triggered()
{
    mCurDrawType = DCircle;
}

