#include "lecteurdico.h"


LecteurDico::LecteurDico(QString* fileDIco)
{
    this->dico = this->dicoToTab(fileDIco);

}

QVector<QVector<QString>> LecteurDico::dicoToTab(QString* fileDico)
{

    QVector<QVector<QString>> dico;

    //Qt prend le chemin absolu, donc mettre dans le dossier debug Qt 5.7 les fichiers que vous voulez afficher
    QFile file(QCoreApplication::applicationDirPath()+fileDico);
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
        //coupe la ligne selon le format du dictionnaire (can_id min,can_id max,fichier correspondant,description can_id)
        wordList.append(line.split(";"));
        QVector<QString> ligneDico;
        for(int i=0;i<wordList.size();i++){
            //ajoute la ligne dans la ligne tableau
            ligneDico.append(wordList.at(i));
        }
        //ajoute la ligne au tableau à double entrée
        dico.append(ligneDico);

    }
    return dico;
}
