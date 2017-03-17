#include "lecteurdico.h"

LecteurDico::LecteurDico()
{

}

QVector<QVector<QString>> LecteurDico::dicoToTab()
{

    QVector<QVector<QString>> dico;
    //Qt prend le chemin absolu, donc mettre dans le dossier debug Qt 5.7 les fichiers que vous voulez afficher
    QFile file(QCoreApplication::applicationDirPath()+"/dicotest2.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    QString line;
    QStringList wordList;
    while(!file.atEnd())
    {
        wordList.clear();
        //lit le fichier dicitonnaire ligne par ligne
        line = file.readLine();
        wordList.append(line.split(";"));
        QVector<QString> ligneDico;
        for(int i=0;i<wordList.size();i++){
            ligneDico.append(wordList.at(i));
        }
        dico.append(ligneDico);

    }
    return dico;
}
