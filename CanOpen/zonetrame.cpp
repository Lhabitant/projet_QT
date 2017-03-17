#include "zonetrame.h"

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
#include <QCanBus>
#include<QDebug>
ZoneTrame::ZoneTrame(QWidget *parent) : QWidget(parent)
{
    QTextEdit *zone;
    QWidget *fenetreLectureTrame;

}

QWidget* ZoneTrame::lectureTrame(QString code)
{
   zone = lecteur(code);
   fenetreLectureTrame = zone;
   fenetreLectureTrame->setStyleSheet("border: 1px solid black;");
   return fenetreLectureTrame;
}
QTextEdit* ZoneTrame::lecteur(QString textLu)
{
    QTextEdit *zone = new QTextEdit;
    zone->setReadOnly(true);
    zone->setPlainText(textLu);
    return zone;
}

void ZoneTrame::ajouterTexte(QString texte)
{
    zone->setText(texte);
}
QWidget* ZoneTrame::LectureBusCan()
{
    /*
     * Penser à voir avec un TextStream
     */
    QByteArray *plugin = new QByteArray("socketcan");
    QString *interface = new QString("can0");
    QCanBusDevice *device = QCanBus::instance()->createDevice(*plugin,*interface);
    device->connectDevice();
    QString view;

    while (device->framesAvailable()>0) {
        const QCanBusFrame frame = device->readFrame();
        view = view + frame.payload();
    }
    /*QCanBusFrame frame = device->readFrame();
    QString *byt = new QString(frame.payload());*/
    qDebug()<< view;
    return lectureTrame(view);
}

