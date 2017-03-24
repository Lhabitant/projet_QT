#include "lecteurdico.h"
#include <stdio.h>


LecteurDico::LecteurDico(QString* fileDIco)
{
    this->dico = this->dicoToTab(*fileDIco);

}

QVector<QVector<QString>> LecteurDico::dicoToTab(QString fileDico)
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


QVector<QVector<QString>> LecteurDico::getTab()
{
    return this->dico;
}

//Traduction d'une trame CANOpen envoyée en paramètre au format renvoyé par QCanBusFrame::toString()
QString LecteurDico::testTraductionTrame(QString* trame)
{
    //on met la trame dans un tableau can_id|length|data
    QStringList trameSplit;
    trameSplit=trame->split("  ");

    //On récupère data dans un QString
    QString data=trameSplit[2];
    data=data.split(" ").join("");

    //On parcours le dictionnaire pour touver la can_id correspondant
    for (int i=0;i<this->dico.length();i++)
    {
        if (trameSplit[0]==this->dico[i][0]){
            //On ouvre le dico correspondant au can_id de la trame
            QVector<QVector<QString>> dicoSpec = this->dicoToTab(dico[i][2]);
            //On cherche la trame dans ce dico
            for (int j=1;j<dicoSpec.length();j++){
                //Si on trouve la trame on renvoie la traduction
                if (data==dicoSpec[j][2]){
                    return dicoSpec[j][3];
                }
            }
        }
    }

    //Si la trame n'a pas été trouvée dans le dico
    return "UNKNOWN_FRAME_ERROR";
}
