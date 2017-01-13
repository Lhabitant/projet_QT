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
    buttonTabBas *filtre4 = new buttonTabBas("f4",&*filtres);
    buttonTabBas *filtre5 = new buttonTabBas("f5",&*filtres);
    buttonTabBas *filtre6 = new buttonTabBas("f6",&*filtres);
    baba->setLayout(filtres);

    QHBoxLayout *gestionBus = new QHBoxLayout(this);
    QWidget *gBus = new QWidget();
    QComboBox *test = new QComboBox();
    test->addItem("Tous les noeuds");
    test->addItem("noeud1");
    gestionBus->addWidget(test);
    QPushButton *Op = new QPushButton("Opérationnel");
    gestionBus->addWidget(Op);
    QPushButton *PreOp = new QPushButton("Pré-opérationnel");
    gestionBus->addWidget(PreOp);
    QPushButton *Stop = new QPushButton("Stop");
    gestionBus->addWidget(Stop);
    QPushButton *Rest = new QPushButton("Rest");
    gestionBus->addWidget(Rest);
    QPushButton *Reset = new QPushButton("Reset");
    gestionBus->addWidget(Reset);
    gBus->setLayout(gestionBus);



    QWidget *console = new QWidget(this);
    onglets.addTab(baba,"Filtres");
    onglets.addTab(console,"Console");
    onglets.addTab(gBus,"NMT");
}

