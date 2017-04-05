#ifndef ZONE_H
#define ZONE_H

#include <QDialog>
#include <QWidget>
#include <QMenuBar>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include "zonebas.h"
#include "zonetrame.h"

class Zone : public QDialog
{
    Q_OBJECT
public:
    Zone(QWidget*& zone1, QWidget*& zone2, zoneBas*& zone3);
    Zone(QWidget*& zone1,QWidget*& zone2,zoneBas*& zone3,ZoneTrame *& zonetrame);
private:
    void createMenu();
    void createHorizontalGroupBox(QWidget*& zone1,QWidget*& zone2);

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    ZoneTrame *zonetrame;

    QMenu *fileMenu;
    QAction *exitAction;
public slots:
    void switchC();
};

#endif // ZONE_H
