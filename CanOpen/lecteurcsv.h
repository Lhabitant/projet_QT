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
    QStringList extract();
    QString lecture();
    QString QStringListToQString(QStringList liste);
    QString getTile(QStringList liste, int x);
};

#endif // LECTEURCSV_H
