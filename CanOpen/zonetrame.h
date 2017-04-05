#ifndef ZONETRAMEBRUTE_H
#define ZONETRAMEBRUTE_H

#include <QWidget>
#include <QTextEdit>
#include <QCanBus>
#include<QDebug>
class ZoneTrame : public QWidget
{
public:
    QTextEdit *zone;
    QWidget *fenetreLectureTrame;
    QCanBusDevice *device;
    QString *allFrames;

    QWidget *lectureTrame(QString code);
    QTextEdit* lecteur(QString text);
    void ajouterTexte(QString texte);
    void *LectureBusCan(QWidget *zoneDetexte);


    Q_OBJECT
public:
    explicit ZoneTrame(QWidget *parent = 0);
    QCanBusFrame lireTrame();

signals:

public slots:
};

#endif // ZONETRAMEBRUTE_H
