#include "main.h"
#include <QApplication>
#include <QWidget>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QWidget mainWindow;
    mainWindow.resize(mainWindow.maximumWidth(),mainWindow.maximumHeight());
    mainWindow.show();

    return app.exec();
}
