#ifndef ZONETRAMEBRUTE_H
#define ZONETRAMEBRUTE_H

#include <QWidget>
#include <QTextEdit>

class ZoneTrame : public QWidget
{
public:

    QWidget *creaZone(QString name, QString code);
    QTextEdit* texteEdit(QString text);

    Q_OBJECT
public:
    explicit ZoneTrame(QWidget *parent = 0);

signals:

public slots:
};

#endif // ZONETRAMEBRUTE_H
