#include "main.h"
#include <thread>
#include <iostream>
#include <mutex>
int switchCapture =0;

int main(int argc, char *argv[])
{

    QApplication app(argc,argv);
    LecteurCSV *dico = new LecteurCSV();
    Trad *traducteur = new Trad;
    QStringList test = dico->extractLine();
    //QString txtDroit =  dico->lecture();
    QString txtGauche = dico->lecture();


    QString fileDico = "/dicotest2.csv";
    //On ouvre le dictionnaire et le place dans un tableau à double entrée
    LecteurDico *dicTest = new LecteurDico(&fileDico);
    QVector<QVector<QString>> dicoV1 = dicTest->getTab();


    //Exemple de trame convertie en chaine de caractères et test de traduction
    QString *trameText = new QString("400  [6]  05 01 01 00 3 01");
    QString txtDroit = dicTest->traductionTrame(trameText);

    QFile file(QCoreApplication::applicationDirPath()+"/trameTest.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    QString line;
    line = file.readLine();


    ZoneTrame *lecteurTrame = new ZoneTrame;
    zoneBas *bas = new zoneBas();
    QWidget *gauche = lecteurTrame->lectureTrame(txtGauche);


    QWidget *droite = lecteurTrame->lectureTrame(txtDroit);

    //QString framereceive=lecteurTrame->lireTrame();
    //QWidget *droite = lecteurTrame->lectureTrame(framereceive);

    Zone first(gauche,droite,bas,lecteurTrame);
    first.show();

    //qDebug() << "Kappa";
    /*for(int i; i<100; i++)
    {
        txtDroit = txtDroit+ " " + QString::number(i);
        lecteurTrame->ajouterTexte(txtDroit);
        // fat le faire attendre ici
    }*/


    return app.exec();

}
