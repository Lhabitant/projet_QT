#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QCoreApplication>
#include <QString>

#include "lecteurcsv.h"

LecteurCSV::LecteurCSV()
{

}

QStringList LecteurCSV::extract()
{
    //Qt prend le chemin absolu, donc mettre dans le dossier debug Qt 5.7 les fichiers que vous voulez afficher
    QFile file(QCoreApplication::applicationDirPath()+"/dicotest.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }

    QStringList wordList;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        wordList.append(line.split(';').first());
    }

    qDebug() << wordList;

    return  wordList;
}

QString LecteurCSV::lecture()
{
    QStringList liste = extract();
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
