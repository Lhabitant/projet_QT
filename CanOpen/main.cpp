#include "main.h"
#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QDialog>
#include "zone.h"
#include "zonetrame.h"
#include "zonebas.h"
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    /*QWidget mainWindow;
    mainWindow.resize(mainWindow.maximumWidth(),mainWindow.maximumHeight());

    ZoneTrame tradWindow(&mainWindow);
    tradWindow.setStyleSheet("border: 1px solid black;");
    QLabel lab("zone traduite",&tradWindow);
    lab.setMinimumHeight(tradWindow.height());
    lab.setMinimumWidth(tradWindow.width());
    //lab.setFrameRect(QRect(0,0,0,0));


    ZoneTrame brutWindow(&mainWindow);
    brutWindow.setStyleSheet("background-color: rgba(255,0,0,0.3);");
    QLabel bal("zone brute",&brutWindow);
    bal.setMinimumHeight(brutWindow.height());
    bal.setMinimumWidth(brutWindow.width());
    bal.text();

    QHBoxLayout layoutSuperieur;
    layoutSuperieur.addWidget(&tradWindow);
    layoutSuperieur.addWidget(&brutWindow);




    QVBoxLayout lay;
    lay.addLayout(&layoutSuperieur);
    mainWindow.setLayout(&lay);
    ZoneTrame hehe(&mainWindow);
    lay.addWidget(&hehe);


    QPushButton quit("Quitter",&mainWindow);
    quit.move(870,850);

    QObject::connect(&quit,SIGNAL(clicked()),qApp,SLOT(quit()));*/


    QWidget mainWindow;
    mainWindow.resize(mainWindow.maximumWidth(),mainWindow.maximumHeight());

    QWidget *zbra = new ZoneTrame(&mainWindow);
    zbra->resize(500,400);
    zbra->setStyleSheet("border: 1px solid black;");

    QWidget *zbwi = new ZoneTrame(&mainWindow);
    zbwi->resize(500,400);
    zbwi->setStyleSheet("border: 1px solid red");


    zoneBas *bas = new zoneBas(&mainWindow);
    bas->setStyleSheet("background-color: red;");
    bas->move(0,500);

    Zone first(zbra,zbwi,bas,&mainWindow);

    QPushButton quit("Quitter",&mainWindow);
    quit.move(870,850);

    QObject::connect(&quit,SIGNAL(clicked()),qApp,SLOT(quit()));

    mainWindow.show();
    return app.exec();
}
