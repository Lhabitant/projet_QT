#include "test.h"
#include <QtSerialPort/QSerialPort>


TEST::TEST()
{

}

void TEST::blbl()
{
    QextSerialPort *port;

    // création du port en mode asynchrone -> QextSerialPort::Polling
    port = new QextSerialPort(QLatin1String(PORT), QextSerialPort::Polling);

    // TODO : paramètrer le port (débit, ...)

    // ouverture du port
    port->open(QIODevice::ReadWrite | QIODevice::Unbuffered);
    #ifdef DEBUG
    qDebug("<debug> etat ouverture port : %d", port->isOpen());
    #endif

    // TODO : réceptionner des données

    // fermeture du port
    port->close();
    #ifdef DEBUG
    qDebug("<debug> etat ouverture port : %d", port->isOpen());
    #endif

    delete port;

    return 0;

}
