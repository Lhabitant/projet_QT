#include "main.h"
#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include "zonetrame.h"
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QWidget mainWindow;
    mainWindow.resize(mainWindow.maximumWidth(),mainWindow.maximumHeight());

    ZoneTrame tradWindow(&mainWindow);
    QLabel lab("zone traduite",&tradWindow);
    lab.setMinimumHeight(tradWindow.height());
    lab.setMinimumWidth(tradWindow.width());
    //lab.setFrameRect(QRect(0,0,0,0));
    tradWindow.setStyleSheet("border: 1px solid black;");

    ZoneTrame brutWindow(&mainWindow);
    QLabel bal("zone brute",&brutWindow);
    bal.setMinimumHeight(brutWindow.height());
    bal.setMinimumWidth(brutWindow.width());
    bal.text();
    brutWindow.setStyleSheet("background-color: rgba(255,0,0,0.3);");

    QHBoxLayout layoutSuperieur;
    layoutSuperieur.addWidget(&tradWindow);
    layoutSuperieur.addWidget(&brutWindow);
    mainWindow.setLayout(&layoutSuperieur);

    QPushButton quit("Quitter",&mainWindow);
    quit.move(870,850);

    QObject::connect(&quit,SIGNAL(clicked()),qApp,SLOT(quit()));
    mainWindow.show();

    return app.exec();
}
