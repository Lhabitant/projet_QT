#include "buttontabbas.h"
#include "QPushButton"
#include "QString"
#include "QBoxLayout"

buttonTabBas::buttonTabBas(const QString name,QGridLayout* parent)
{
    this->setText(name);
    this->setMaximumWidth(100);
    parent->addWidget(this,0,parent->count(),0,10);


}
