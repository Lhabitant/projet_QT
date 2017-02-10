#include "zoneconsole.h"

zoneConsole::zoneConsole(QWidget *parent) : QWidget(parent)
{
    QGridLayout *console = new QGridLayout(this);
    this->sortieConsole = new QTextEdit("sortie console",this);
    this->sortieConsole->setReadOnly(true);
    this->entreeConsole =new QLineEdit(this);

    QPushButton *validConsole = new QPushButton("Envoyer",this);

    console->addWidget(this->sortieConsole,0,0,1,1);
    console->addWidget(this->entreeConsole,3,0,3,1);
    console->addWidget(validConsole,3,1,1,3);

    connect(this->entreeConsole,SIGNAL(textChanged(const QString&)),this,SLOT(recupererCommande(QString)));
    connect(validConsole,SIGNAL(clicked(bool)),this,SLOT(envoyerCommande()));

    this->setLayout(console);
}

void zoneConsole::recupererCommande(QString commande){
    this->str = commande;
}

void zoneConsole::envoyerCommande(){
    this->sortieConsole->setPlainText(this->str);
}
