#include "zone.h"
#include <QVBoxLayout>
Zone::Zone(QWidget &zone1,QWidget &zone2,QWidget &zone3)
{
    createMenu();
    createHorizontalGroupBox(zone1,zone2);


    QVBoxLayout mainLayout;
    mainLayout.setMenuBar(menuBar);

    mainLayout.addWidget(horizontalGroupBox);
    mainLayout.addWidget(zone3);

    setLayout(mainLayout);
}
void Zone::createMenu()
{
    menuBar = new QMenuBar;
    fileMenu = new QMenu(tr("File"),this);
    exitAction = fileMenu->addAction(tr("Exit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction,SIGNAL(triggered()),this,SLOT(accept()));
}
void Zone::createHorizontalGroupBox(QWidget zoneGauche,QWidget zoneDroite)
{
    horizontalGroupBox = new QGroupBox(tr("Affichage supérieur"));
    QHBoxLayout layout;
    layout.addWidget(&zoneGauche);
    layout.addWidget(&zoneDroite);

    horizontalGroupBox->setLayout(&layout);
}
