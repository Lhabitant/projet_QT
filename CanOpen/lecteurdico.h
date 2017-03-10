#ifndef LECTEURDICO_H
#define LECTEURDICO_H

#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QVector>

class LecteurDico
{
public:
    LecteurDico();
    QVector<QVector<QString>> dicoToTab();
};

#endif // LECTEURDICO_H
