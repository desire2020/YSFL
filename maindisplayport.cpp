#include "maindisplayport.hpp"
#include "ui_maindisplayport.h"

MainDisplayPort::MainDisplayPort(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDisplayPort)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    setFixedSize(1440,900);
}

MainDisplayPort::~MainDisplayPort()
{
    delete ui;
}
