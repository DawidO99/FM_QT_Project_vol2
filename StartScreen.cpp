#include "StartScreen.h"

StartScreen::StartScreen(QWidget *parent): QMainWindow(parent)
{
    this->setWindowState(Qt::WindowMaximized);
    ui.setupUi(this);
}

StartScreen::~StartScreen()
{}
