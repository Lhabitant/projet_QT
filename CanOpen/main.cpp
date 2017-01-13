#include "main.h"
#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QDialog>
#include <QTextEdit>
#include "zone.h"
#include "zonetrame.h"
#include "zonebas.h"
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QTextEdit *a = new QTextEdit;
    a->setReadOnly(true);
    a->setPlainText("trolololol");
    QWidget *zbra = a;
    zbra->setStyleSheet("border: 1px solid black;");

    QTextEdit *b = new QTextEdit;
    b->setReadOnly(true);
    b->setPlainText("trelelelel");
    QWidget *zbwi = b;
    zbwi->setStyleSheet("border: 1px solid red;");

    zoneBas *bas = new zoneBas();

    Zone first(zbra,zbwi,bas);

    first.show();
    return app.exec();
}
