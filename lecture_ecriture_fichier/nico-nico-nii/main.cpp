#include <QApplication>
#include <QTextEdit>   // Nous allons tout de même afficher le contenu du fichier ^^
#include <QFile>       // Pour utiliser le fichier
#include <QString>     // Stocke le contenu du fichier
#include <QTextStream> // Flux sortant du fichier
#include <QTextCodec>
#include <QPushButton>
#include <QDir>

QString readByFlux(QFile *test, int colunmNeeded){
    QString text,texte;
    QStringList list;
    QTextStream flux(test); // on ouvre un flux de lecture sur le fichier (c'est une autre méthode)
    while (!flux.atEnd()){
        text=flux.readLine();
        list=text.split(',');
        texte+=list.at(colunmNeeded)+'\n';
        texte.resize(texte.size()-1);
    }
    return texte;
}

QString readByBuffer(QFile* test){
    QString texte;
    texte = test->readAll(); //on stocke tout dans une string
    test->close();
    return texte;
}

int main(int argc, char *argv[]){
    // UTF-8 Encoding
   // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
   //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
   //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); // ces trois lignes servent a afficher en utf8
    QApplication a(argc, argv);
    QDir::setCurrent(QDir::currentPath());
    QString texte;
    QTextEdit zoneTexte; //on crée une zone de texte
    zoneTexte.setGeometry(300,300,400,300); //useless, taille de la zone de texte
    zoneTexte.setReadOnly(true); //on ne peut pas modifier la zone de texte
    QFile *test1 = new QFile(QCoreApplication::applicationDirPath()+"/yolo.txt"); //Qt prend le chemin absolu, donc mettre dans le dossier debug Qt 5.7 les fichiers que vous voulez afficher
    if(test1->open(QIODevice::ReadOnly)) // test sur l'ouverture du fichier
    {
        texte=readByBuffer(test1);
    }
    else
        texte="Impossible d'ouvrir le fichier !";
    zoneTexte.setText(texte); //on affiche le texte lu dans la zone
    zoneTexte.show(); // on affiche la zone de texte
    return a.exec();
}
