#include "StartScreen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("MiniFootballManager");
    app.setApplicationDisplayName("MiniFootballManager");
    StartScreen MainWindow;
    MainWindow.setWindowTitle(app.applicationDisplayName());
    QIcon appIcon("images/matchday.jpg");
    MainWindow.setWindowIcon(appIcon);
    MainWindow.show();
    return app.exec();
}
