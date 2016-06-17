#include "maindisplayport.hpp"
#include "class_cellular_automata.hpp"
#include <QApplication>
using YSFL :: cellular_automata;
using YSFL :: simulated_world;
void initialization()
{
    YSFL :: all_cells.push_back(cellular_automata("if equals detect 1 3 born die)"));
    YSFL :: all_cells.push_back(cellular_automata("if equals detect 1 2 still if equals detect 1 3 born die"));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDisplayPort w;
    w.show();

    return a.exec();
}
