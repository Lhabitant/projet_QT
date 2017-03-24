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
private:
    QVector<QVector<QString>> dico;
public:
    LecteurDico(QString* fileDico);
    QVector<QVector<QString>> dicoToTab(QString* fileDico);
};

#endif // LECTEURDICO_H
