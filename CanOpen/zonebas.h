#ifndef ZONEBAS_H
#define ZONEBAS_H

#include <QWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QComboBox>
#include <QFormLayout>
#include <QTextEdit>
#include "zoneconsole.h"

class zoneBas : public QWidget
{
    Q_OBJECT
public:
    zoneBas(QWidget* parent=0);
private:
    void createOnglets(QTabWidget& onglets);

signals:
    void lireConsole(QString texte);

public slots:
};

#endif // ZONEBAS_H
