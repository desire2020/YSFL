#include "maindisplayport.hpp"
#include "class_cellular_automata.hpp"
#include <QApplication>
#include <QGraphicsItem>
#include <QPainter>
#include <fstream>
#include <iostream>
using std :: ifstream;
using YSFL :: cellular_automata;
using YSFL :: simulated_world;
using YSFL :: dict;
void initialization()
{
    dict[string("TTT")] = 0;
    dict[string("TTC")] = 0;
    dict[string("TTA")] = 1;
    dict[string("TTG")] = 1;
    dict[string("CTA")] = 1;
    dict[string("CTT")] = 1;
    dict[string("CTC")] = 1;
    dict[string("CTG")] = 1;
    dict[string("ATA")] = 2;
    dict[string("ATT")] = 2;
    dict[string("ATC")] = 2;
    dict[string("TCA")] = 3;
    dict[string("TCT")] = 3;
    dict[string("TCC")] = 3;
    dict[string("TCG")] = 3;
    dict[string("CCA")] = 4;
    dict[string("CCT")] = 4;
    dict[string("CCC")] = 4;
    dict[string("CCG")] = 4;
    dict[string("ACA")] = 5;
    dict[string("ACT")] = 5;
    dict[string("ACC")] = 5;
    dict[string("ACG")] = 5;
    dict[string("GTA")] = 6;
    dict[string("GCA")] = 7;
    dict[string("TAA")] = 8;
    dict[string("CAA")] = 9;
    dict[string("AAA")] = 10;
    dict[string("GAA")] = 11;
    dict[string("TGA")] = 12;
    dict[string("CGA")] = 13;
    dict[string("AGA")] = 14;
    dict[string("GGA")] = 15;
    dict[string("GTT")] = 6;
    dict[string("GCT")] = 7;
    dict[string("TAT")] = 8;
    dict[string("CAT")] = 9;
    dict[string("AAT")] = 10;
    dict[string("GAT")] = 11;
    dict[string("TGT")] = 12;
    dict[string("CGT")] = 13;
    dict[string("AGT")] = 14;
    dict[string("GGT")] = 15;
    dict[string("GTC")] = 6;
    dict[string("GCC")] = 7;
    dict[string("TAC")] = 8;
    dict[string("CAC")] = 9;
    dict[string("AAC")] = 10;
    dict[string("GAC")] = 11;
    dict[string("TGC")] = 12;
    dict[string("CGC")] = 13;
    dict[string("AGC")] = 14;
    dict[string("GGC")] = 15;
    dict[string("GTG")] = 6;
    dict[string("GCG")] = 7;
    dict[string("TAG")] = 8;
    dict[string("CAG")] = 9;
    dict[string("AAG")] = 10;
    dict[string("GAG")] = 11;
    dict[string("TGG")] = 12;
    dict[string("CGG")] = 13;
    dict[string("AGG")] = 14;
    dict[string("GGG")] = 15;
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
    scene.addRect(QRect(0, 0, 900, 900));
    scene.clear();
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
