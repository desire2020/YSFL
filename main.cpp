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
    dict["TTC"] = 0;
    dict["TTA"] = 1;
    dict["TTG"] = 1;
    dict["CTA"] = 1;
    dict["CTT"] = 1;
    dict["CTC"] = 1;
    dict["CTG"] = 1;
    dict["ATA"] = 2;
    dict["ATC"] = 2;
    dict["ATG"] = 2;
    dict["ATT"] = 2;
    dict["TCA"] = 3;
    dict["TCT"] = 3;
    dict["TCC"] = 3;
    dict["TCG"] = 3;
    dict["CCA"] = 4;
    dict["CCT"] = 4;
    dict["CCC"] = 4;
    dict["CCG"] = 4;
    dict["ACA"] = 5;
    dict["ACT"] = 5;
    dict["ACC"] = 5;
    dict["ACG"] = 5;
    dict["GTA"] = 6;
    dict["GTT"] = 6;
    dict["GTC"] = 6;
    dict["GTH"] = 6;
    dict["GCA"] = 7;
    dict["GCT"] = 7;
    dict["GCC"] = 7;
    dict["GCG"] = 7;
    dict["TAA"] = 8;
    dict["TAT"] = 8;
    dict["TAC"] = 8;
    dict["TAG"] = 8;
    dict["CAA"] = 9;
    dict["CAT"] = 9;
    dict["CAC"] = 9;
    dict["CAG"] = 9;
    dict["AAA"] = 10;
    dict["AAT"] = 10;
    dict["AAC"] = 10;
    dict["AAG"] = 10;
    dict["GAA"] = 11;
    dict["GAT"] = 11;
    dict["GAC"] = 11;
    dict["GAG"] = 11;
    dict["TGA"] = 12;
    dict["TGT"] = 12;
    dict["TGC"] = 12;
    dict["TGG"] = 12;
    dict["CGA"] = 13;
    dict["CGT"] = 13;
    dict["CGC"] = 13;
    dict["CGG"] = 13;
    dict["AGA"] = 14;
    dict["AGT"] = 14;
    dict["AGC"] = 14;
    dict["AGG"] = 14;
    dict["GGA"] = 15;
    dict["GGT"] = 15;
    dict["GGC"] = 15;
    dict["GGG"] = 15;

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
