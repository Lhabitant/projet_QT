#include "main.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    LecteurCSV *dico = new LecteurCSV();
    Trad *traducteur = new Trad;
    QStringList test = dico->extractLine();
    QString txtDroit =  dico->lecture();
    QString txtGauche = dico->lecture();


    QString fileDico = "dicotest2.csv";
    //On ouvre le dictionnaire et le place dans un tableau à double entrée
    LecteurDico *dicTest = new LecteurDico(&fileDico);
    QVector<QVector<QString>> dicoV1 = dicTest->getTab();


    QFile file(QCoreApplication::applicationDirPath()+"/trameTest.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    QString line;
    line = file.readLine();

    QString *trameText = new QString("205  [2]  01 3F");

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
