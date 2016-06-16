#include "maindisplayport.hpp"
#include "class_cellular_automata.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDisplayPort w;
    w.show();

    return a.exec();
}
