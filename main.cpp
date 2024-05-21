#include "StartScreen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    StartScreen MainWindow;
    MainWindow.show();
    return app.exec();
}
