#include "StartScreen.h"

StartScreen::StartScreen(QWidget *parent): QMainWindow(parent)
{
    this->setWindowState(Qt::WindowMaximized);
    ui.setupUi(this);
    ui.stackedWidget_start_screen->addWidget(&NewGame_class);
}

StartScreen::~StartScreen()
{}
void StartScreen::on_pushButton_start_game_clicked()
{
    ui.stackedWidget_start_screen->setCurrentIndex(1);
}
