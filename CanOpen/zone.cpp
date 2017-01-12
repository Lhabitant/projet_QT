#include "zone.h"
#include <QVBoxLayout>
#include "zonebas.h"
Zone::Zone(QWidget*& zone1,QWidget*& zone2,zoneBas*& zone3,QWidget* parent)
{
    this->resize(parent->width(),parent->height());
    this->setParent(parent);



    createMenu();
    createHorizontalGroupBox(zone1,zone2);


    QVBoxLayout *mainLayout= new QVBoxLayout(this);
    mainLayout->setMenuBar(menuBar);

    mainLayout->addWidget(horizontalGroupBox);
    mainLayout->addWidget(zone3);

    this->setLayout(mainLayout);
}
void Zone::createMenu()
{
    menuBar = new QMenuBar;
    fileMenu = new QMenu(tr("File"),this);
    exitAction = fileMenu->addAction(tr("Exit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction,SIGNAL(triggered()),this,SLOT(accept()));
}
void Zone::createHorizontalGroupBox(QWidget*& zoneGauche,QWidget*& zoneDroite)
{
    horizontalGroupBox = new QGroupBox(tr("Affichage supérieur"));
    QHBoxLayout *layout= new QHBoxLayout(horizontalGroupBox);
    zoneGauche->resize(this->width()/2,this->height()/2);
    layout->addWidget(zoneGauche,0,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(zoneDroite,0,Qt::AlignTop);
    horizontalGroupBox->setLayout(layout);

}
