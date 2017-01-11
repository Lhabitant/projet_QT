#ifndef ZONEBAS_H
#define ZONEBAS_H

#include <QWidget>
#include <QTabWidget>
#include <QPushButton>

class zoneBas : public QWidget
{
    Q_OBJECT
public:
    zoneBas(QWidget* parent);
private:
    void createOnglets(QTabWidget& onglets);

signals:

public slots:
};

#endif // ZONEBAS_H
