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

class Zone : public QDialog
{
public:
    Zone(QWidget*& zone1,QWidget*& zone2,zoneBas*& zone3);
private:
    void createMenu();
    void createHorizontalGroupBox(QWidget*& zone1,QWidget*& zone2);

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;

    QMenu *fileMenu;
    QAction *exitAction;
};

#endif // ZONE_H
