#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QDialog>
#include <QTextEdit>
#include <QString>

#include "zone.h"
#include "zonetrame.h"
#include "zonebas.h"
#include "main.h"


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QString test ="zone trames brutes";
    QString test1 = "zone messages traduits";
    ZoneTrame *TEST = new ZoneTrame;
    zoneBas *bas = new zoneBas();
    QWidget *gauche = TEST->creaZone(test1,test1);
    QWidget *droite = TEST->creaZone(test,test);

    Zone first(gauche,droite,bas);

    first.show();
    return app.exec();
}
