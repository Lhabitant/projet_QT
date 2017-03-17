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
    for(int i =0; !file.atEnd(); i++)
    {

        //extrait qu'une ligne du dico ajoute \n et supprime le ";"
        line = file.readLine();
        wordList.append(line.split(";"));
        QVector<QString> ligneDico;
        for(int j=0;j<wordList.size();j++){
            ligneDico.append(wordList.takeAt(j));
        }
        dico.append(ligneDico);

    }
    return dico;
}
