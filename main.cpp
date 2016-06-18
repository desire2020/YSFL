#include "maindisplayport.hpp"
#include "class_cellular_automata.hpp"
#include <QApplication>
#include <QGraphicsItem>
#include <QPainter>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using YSFL :: cellular_automata;
using YSFL :: simulated_world;
using YSFL :: dict;
void create_new()
{
    ofstream fout("settings.ini");
    fout << "TTTTTGATAGTATAXTCTCCG\nTTTTTGATAGTAGCTACATTCTTGATTGTTTAXTCCCCA\n";
    fout.close();
}
void initialization()
{
    ifstream fin("settings.ini");
    if (!fin.is_open())
    {
        create_new();
        QMessageBox::about(NULL, "", "基因信息已重置");
        fin.open("settings.ini", ios :: in);
    }
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;
    dict["TTT"] = 0;

    string inp;
    fin >> inp;
    YSFL :: all_cells.push_back(cellular_automata(inp));
    fin >> inp;
    YSFL :: all_cells.push_back(cellular_automata(inp));
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainDisplayPort w;
    QGraphicsScene scene;
    YSFL :: DisplayScene = &scene;
    scene.setSceneRect(0,0,900,900);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    QGraphicsView view(&scene);
    YSFL :: DisplayView = &view;
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
