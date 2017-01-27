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


}

QWidget* ZoneTrame::lectureTrame(QString code)
{
   QTextEdit *zone = lecteur(code);
   QWidget *fenetreLectureTrame = zone;
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


