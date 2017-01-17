#ifndef TRAD_H
#define TRAD_H

#include <QString>
#include <QFile>

class Trad
{
public:
    Trad();
    QString readByFlux(QFile *test, int colunmNeeded);
    QString readByBuffer(QFile* test);
    QString translate();
};

#endif // TRAD_H
