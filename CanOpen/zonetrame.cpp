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

ZoneTrame::ZoneTrame(QWidget *parent) : QWidget(parent)
{
    QTextEdit *zone;
    QWidget *fenetreLectureTrame;
    QCanBusDevice *device;


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
void* ZoneTrame::LectureBusCan(QWidget *zoneDeTexte)
{
    /*
     * Penser à voir avec un TextStream
     */
    if (!QCanBus::instance()->plugins().contains(QStringLiteral("socketcan"))) {
        qDebug() << "Aie";
    }
    QByteArray *plugin = new QByteArray("socketcan");
    QString *interface = new QString("can0");
    device = QCanBus::instance()->createDevice(*plugin,*interface);
    if(!device->connectDevice()){
        qDebug() << "Device non connecté";
    }

    //connect(device, &QCanBusDevice::framesReceived,this, &ZoneTrame::checkMessages);


    //zoneDeTexte->append(*allFrames);
}

QCanBusFrame ZoneTrame::lireTrame(){

    return device->readFrame();


}

