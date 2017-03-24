#include "main.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    LecteurCSV *dico = new LecteurCSV();
    Trad *traducteur = new Trad;
    QStringList test = dico->extractLine();
    QString txtDroit =  dico->lecture();
    QString txtGauche = dico->lecture();

    //On ouvre le dictionnaire et le place dans un tableau à double entrée
    LecteurDico *dicTest = new LecteurDico();
    QVector<QVector<QString>> dicoV1;
    dicoV1 = dicTest->dicoToTab();


    QFile file(QCoreApplication::applicationDirPath()+"/trameTest.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    QString line;
    line = file.readLine();

    QString *trameText = new QString("205  [2]  01 3F");

    dicTest->tradTrame(trameText);

    ZoneTrame *lecteurTrame = new ZoneTrame;
    zoneBas *bas = new zoneBas();
    QWidget *gauche = lecteurTrame->lectureTrame(txtGauche);
    QWidget *droite = lecteurTrame->lectureTrame(txtDroit);
    //QWidget *droite = lecteurTrame->LectureBusCan();
    Zone first(gauche,droite,bas);
    first.show();
    for(int i; i<100; i++)
    {
        txtDroit = txtDroit+ " " + QString::number(i);
        lecteurTrame->ajouterTexte(txtDroit);
        // fat le faire attendre ici
    }
    return app.exec();

}
