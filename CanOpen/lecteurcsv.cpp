#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QCoreApplication>
#include <QString>

#include "lecteurcsv.h"

LecteurCSV::LecteurCSV()
{

}

QStringList LecteurCSV::extractLine()
{
    //Qt prend le chemin absolu, donc mettre dans le dossier debug Qt 5.7 les fichiers que vous voulez afficher
    QFile file(QCoreApplication::applicationDirPath()+"/dicotest.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    QString line;
    QStringList wordList;
    for(int i =0; !file.atEnd(); i++)
    {

        //extrait qu'une ligne du dico ajoute \n et supprime le ";"
        line = file.readLine();
        line.append("\n");
        wordList.append(line.split(";"));

    }

    qDebug() << wordList;

    return  wordList;
}

QString LecteurCSV::lecture()
{
    QStringList liste = extractLine();
    QString texte = QStringListToQString(liste);
    return texte;
}

QString LecteurCSV::QStringListToQString(QStringList liste)
{
    QString texte = liste.join(" ");
    return texte;
}

QString LecteurCSV::getTile(QStringList liste,int x)
{
    QString tile = liste.at(x);
    return tile;
}



/*
QString line;
QStringList listeDeMots;

line = file.readline();
listeDeMots = line.split(";");
*/
