#include "maindisplayport.hpp"
#include "class_cellular_automata.hpp"
#include "ui_maindisplayport.h"
#include <QMessageBox>

MainDisplayPort::MainDisplayPort(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDisplayPort)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    setFixedSize(1000,900);
}

MainDisplayPort::~MainDisplayPort()
{
    delete ui;
}

void MainDisplayPort::on_pushButton_clicked()
{
    YSFL :: universe_616.evolute();
    YSFL :: universe_616.print(*(this -> ui -> graphicsView));
    QMessageBox::about(NULL, "", "Done");
}

void MainDisplayPort::on_pushButton_2_clicked()
{

}

void MainDisplayPort::on_pushButton_4_clicked()
{
    YSFL :: universe_616.randomize();
    YSFL :: universe_616.print(*(this -> ui -> graphicsView));
}
