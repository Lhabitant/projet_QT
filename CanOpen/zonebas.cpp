#include "zonebas.h"
#include "QTabWidget"
#include "QPushButton"

zoneBas::zoneBas(QWidget *parent) : QWidget(parent)
{

    QTabWidget *o = new QTabWidget(this);
    QTabWidget &onglets = *o;
    createOnglets(onglets);
}

void zoneBas::createOnglets(QTabWidget& onglets){
    QPushButton *filtres = new QPushButton("filtre",this);
    QPushButton *console = new QPushButton("Console",this);
    onglets.addTab(filtres,"Filtres");
    onglets.addTab(console,"Console");
}

