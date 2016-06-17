#ifndef MAINDISPLAYPORT_HPP
#define MAINDISPLAYPORT_HPP

#include <QMainWindow>

namespace Ui {
class MainDisplayPort;
}

class MainDisplayPort : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainDisplayPort(QWidget *parent = 0);
    ~MainDisplayPort();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainDisplayPort *ui;
};

#endif // MAINDISPLAYPORT_HPP
