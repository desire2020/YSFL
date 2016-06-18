#ifndef MAINDISPLAYPORT_HPP
#define MAINDISPLAYPORT_HPP

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
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

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

public:
    Ui::MainDisplayPort *ui;
};

#endif // MAINDISPLAYPORT_HPP
