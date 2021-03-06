#include "zone.h"
#include <QVBoxLayout>
#include "zonebas.h"
#include "zonetrame.h"

extern int  switchCapture;

Zone::Zone(QWidget*& zone1,QWidget*& zone2,zoneBas*& zone3)
{
    //this->resize(parent->width(),parent->height());
    //this->setParent(parent);

    this->resize(this->maximumWidth(),this->maximumHeight());

    createMenu();
    createHorizontalGroupBox(zone1,zone2);


    QVBoxLayout *mainLayout= new QVBoxLayout(this);
    mainLayout->setMenuBar(menuBar);

    mainLayout->addWidget(horizontalGroupBox,3);
    mainLayout->addWidget(zone3,1);


    this->setLayout(mainLayout);
    this->setWindowFlags(Qt::WindowTitleHint); // permet de rajouter les boutons réduire, agrandir, fermer
}
Zone::Zone(QWidget*& zone1,QWidget*& zone2,zoneBas*& zone3,ZoneTrame*& zonedetrame)
{
    //this->resize(parent->width(),parent->height());
    //this->setParent(parent);
    zonetrame = zonedetrame;

    this->resize(this->maximumWidth(),this->maximumHeight());

    createMenu();
    createHorizontalGroupBox(zone1,zone2);


    QVBoxLayout *mainLayout= new QVBoxLayout(this);
    mainLayout->setMenuBar(menuBar);

    mainLayout->addWidget(horizontalGroupBox,3);
    mainLayout->addWidget(zone3,1);


    this->setLayout(mainLayout);
    this->setWindowFlags(Qt::WindowTitleHint); // permet de rajouter les boutons réduire, agrandir, fermer
}
void Zone::createMenu()
{
    menuBar = new QMenuBar;
    fileMenu = new QMenu(tr("File"),this);
    exitAction = fileMenu->addAction(tr("Exit"));
    QAction *startCapture = fileMenu->addAction(tr("Démarrer/arrêter capture"));

    menuBar->addMenu(fileMenu);

    QObject::connect(startCapture,SIGNAL(triggered()),this,SLOT(switchC()));

    connect(exitAction,SIGNAL(triggered()),this,SLOT(accept()));
}
void Zone::createHorizontalGroupBox(QWidget*& zoneGauche,QWidget*& zoneDroite)
{
    horizontalGroupBox = new QGroupBox();
    QHBoxLayout *layout= new QHBoxLayout(horizontalGroupBox);
    zoneGauche->resize(this->width()/2,this->height()/2);
    layout->addWidget(zoneGauche);
    layout->addWidget(zoneDroite);
    horizontalGroupBox->setLayout(layout);
    horizontalGroupBox->close();

}

void Zone::switchC(){

    QCanBusFrame trame;
    QString txtTrame;

        while (1){

            trame=zonetrame->lireTrame();
            qDebug() << "test";
            txtTrame=txtTrame+"\n"+trame.toString();
            if(txtTrame.length()>500){
                txtTrame="";
            }
        }

}
