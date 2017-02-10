#ifndef ZONECONSOLE_H
#define ZONECONSOLE_H

#include <QWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QComboBox>
#include <QFormLayout>
#include <QTextEdit>
#include <QLineEdit>


class zoneConsole : public QWidget
{
    Q_OBJECT
public:
    zoneConsole(QWidget *parent=0);
private:
    QTextEdit *sortieConsole;
    QLineEdit *entreeConsole;
    QString str;
public slots:
    void recupererCommande(QString commande);
    void envoyerCommande();

};

#endif // ZONECONSOLE_H
