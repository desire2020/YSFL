#include "maindisplayport.hpp"
#include "class_cellular_automata.hpp"
#include <QApplication>
#include <QGraphicsItem>
#include <QPainter>
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
    QGraphicsScene scene;
    scene.setSceneRect(0,0,900,900);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    QGraphicsView view(&scene);
    view.setFixedSize(1000,1000);
    QGraphicsRectItem *rect = scene.addRect(QRectF(0, 0, 900, 900));
    //QGraphicsItem *item = scene.itemAt(50, 50);
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    //view.resize(400,300);
    view.show();
    w.show();
   // QGraphicsRectItem *rect2 = scene.addRect(QRectF(100, 100, 200, 200));
    return a.exec();
}
