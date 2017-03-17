#ifndef ZONETRAMEBRUTE_H
#define ZONETRAMEBRUTE_H

#include <QWidget>
#include <QTextEdit>

class ZoneTrame : public QWidget
{
public:
    QTextEdit *zone;
    QWidget *fenetreLectureTrame;

    QWidget *lectureTrame(QString code);
    QTextEdit* lecteur(QString text);
    void ajouterTexte(QString texte);
    QWidget *LectureBusCan();

    Q_OBJECT
public:
    explicit ZoneTrame(QWidget *parent = 0);

signals:

public slots:
};

#endif // ZONETRAMEBRUTE_H
