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
#include "trad.h"
#include "lecteurcsv.h"


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    LecteurCSV *dico = new LecteurCSV();

    Trad *traducteur = new Trad;
    QStringList test = dico->extractLine();
    QString txtDroit = dico->getTile(test,1);
    QString txtGauche = dico->lecture();



    ZoneTrame *lecteurTrame = new ZoneTrame;
    zoneBas *bas = new zoneBas();
    QWidget *gauche = lecteurTrame->lectureTrame(txtGauche);
    QWidget *droite = lecteurTrame->lectureTrame(txtDroit);



    Zone first(gauche,droite,bas);
    first.show();
    return app.exec();
}
