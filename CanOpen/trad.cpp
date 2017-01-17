#include <QApplication>
#include <QTextEdit>   // Nous allons tout de même afficher le contenu du fichier ^^
#include <QFile>       // Pour utiliser le fichier
#include <QString>     // Stocke le contenu du fichier
#include <QTextStream> // Flux sortant du fichier
#include <QTextCodec>
#include <QPushButton>
#include <QDir>

#include "trad.h"

Trad::Trad()
{
    QDir::setCurrent(QDir::currentPath());
}

QString Trad::readByFlux(QFile *test, int colunmNeeded){
    QString text,texte;
    QStringList list;
    // on ouvre un flux de lecture sur le fichier (c'est une autre méthode)
    QTextStream flux(test);


    while (!flux.atEnd()){
        text=flux.readLine();
        list=text.split(',');
        texte+=list.at(colunmNeeded)+'\n';
        texte.resize(texte.size()-1);
    }
    return texte;
}

QString Trad::readByBuffer(QFile* test){
    QString texte;
    //on stocke tout dans une string
    texte = test->readAll();
    test->close();
    return texte;
}

QString Trad::translate()
{
    QString texte;
    //Qt prend le chemin absolu, donc mettre dans le dossier debug Qt 5.7 les fichiers que vous voulez afficher
    QFile *test1 = new QFile(QCoreApplication::applicationDirPath()+"/yolo.txt");
    if(test1->open(QIODevice::ReadOnly)) // test sur l'ouverture du fichier
    {
        texte = readByBuffer(test1);
    }
    else
        texte="Impossible d'ouvrir le fichier !";
    return texte;
}
