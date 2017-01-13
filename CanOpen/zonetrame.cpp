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

QWidget* ZoneTrame::creaZone(QString name, QString code)
{
   QTextEdit *zone = texteEdit(code);
   QWidget *gauche = zone;
   gauche->setStyleSheet("border: 1px solid black;");
   return gauche;
}
QTextEdit* ZoneTrame::texteEdit(QString text)
{
    QTextEdit *zone = new QTextEdit;
    zone->setReadOnly(true);
    zone->setPlainText(text);
    return zone;
}
