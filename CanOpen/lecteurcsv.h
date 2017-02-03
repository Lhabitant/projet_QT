#ifndef LECTEURCSV_H
#define LECTEURCSV_H

#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QCoreApplication>
#include <QString>

class LecteurCSV
{
public:
    LecteurCSV();
    QStringList extractLine();
    QString lecture();
    QString QStringListToQString(QStringList liste);
    QString getTileOnLine(QStringList liste, int x);
    QString simulFlux(QStringList liste);

};

#endif // LECTEURCSV_H
