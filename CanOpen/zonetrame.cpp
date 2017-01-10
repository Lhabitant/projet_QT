#include "zonetrame.h"

ZoneTrame::ZoneTrame(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(parent->maximumWidth()/2);
    setFixedHeight(parent->maximumHeight()/2);

}
