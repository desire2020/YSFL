#include "maindisplayport.hpp"
#include "ui_maindisplayport.h"

MainDisplayPort::MainDisplayPort(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDisplayPort)
{
    ui->setupUi(this);
}

MainDisplayPort::~MainDisplayPort()
{
    delete ui;
}
