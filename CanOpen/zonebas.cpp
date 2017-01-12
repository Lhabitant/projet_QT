#include "zonebas.h"
#include "QTabWidget"
#include "QPushButton"
#include "QDialog"
#include "QTextEdit"
#include "QWidget"
#include "QBoxLayout"

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
    QWidget *filtres = new QWidget(this);
    QPushButton *filtre1 = new QPushButton("f1",filtres);
    QPushButton *filtre2 = new QPushButton("f2",filtres);
    //filtres->addWidget(filtre1);
    //filtres->addWidget(filtre2);
    //this->setLayout(filtres);
    QWidget *console = new QWidget(this);
    onglets.addTab(filtres,"Filtres");
    onglets.addTab(console,"Console");
}

