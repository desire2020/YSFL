#include "maindisplayport.hpp"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "class_cellular_automata.hpp"
#include "ui_maindisplayport.h"
#include <QMessageBox>
#include <QThread>

QApplication *inPro;
bool infinity_flag = false;
MainDisplayPort::MainDisplayPort(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDisplayPort)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    setFixedSize(811,640);
    move(1000, 250);
}

MainDisplayPort::~MainDisplayPort()
{
    delete ui;
}

void MainDisplayPort::on_pushButton_clicked()
{
    YSFL :: universe_616.evolve();
    //YSFL :: universe_616.print(DisplayScene, *DisplayArea);
  //  QMessageBox::about(NULL, "", "Done");
}

void MainDisplayPort::on_pushButton_2_clicked()
{
    infinity_flag = true;
    while(infinity_flag)
    {
        on_pushButton_clicked();
        YSFL :: universe_616.print(*YSFL :: DisplayScene, *YSFL :: DisplayView);
        inPro -> processEvents();
       // QMessageBox::about(NULL, "", "Done");
        QThread :: msleep(20);
    }
}

void MainDisplayPort::on_pushButton_4_clicked()
{
    YSFL :: universe_616.randomize();
   // YSFL :: universe_616.print(DisplayScene, *DisplayArea);
}

void MainDisplayPort::on_pushButton_3_clicked()
{
    infinity_flag = false;
}

void MainDisplayPort::closeEvent(QCloseEvent *event)
{
	infinity_flag = false;
	inPro -> exit(0);
}