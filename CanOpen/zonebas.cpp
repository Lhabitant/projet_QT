#include "zonebas.h"
#include "QTabWidget"
#include "QPushButton"
#include "QDialog"
#include "QTextEdit"
#include "QWidget"
#include "QBoxLayout"
#include "buttontabbas.h"

zoneBas::zoneBas(QWidget *parent) : QWidget(parent)
{
    QBoxLayout *layoutBas= new QBoxLayout(QBoxLayout::LeftToRight,this);
    QTabWidget *o = new QTabWidget(this);
    QTabWidget &onglets = *o;
    createOnglets(onglets);
    layoutBas->addWidget(&onglets);
    this->setLayout(layoutBas);
}

void zoneBas::createOnglets(QTabWidget& onglets){
    QGridLayout *filtres = new QGridLayout(this);
    QWidget *baba = new QWidget();
    buttonTabBas *filtre1 = new buttonTabBas("f1",&*filtres);
    buttonTabBas *filtre2 = new buttonTabBas("f2",&*filtres);
    buttonTabBas *filtre3 = new buttonTabBas("f3",&*filtres);
    /*filtre1->setMaximumWidth(this->width()/8);
    filtre2->setMaximumWidth(this->width()/8);
    filtre3->setMaximumWidth(this->width()/8);

    filtres->addWidget(filtre1,0,0,0,10);
    filtres->addWidget(filtre2,0,1,0,10);
    filtres->addWidget(filtre3,0,2,0,10);*/
    baba->setLayout(filtres);


    QWidget *console = new QWidget(this);
    onglets.addTab(baba,"Filtres");
    onglets.addTab(console,"Console");
}

