#include "NewGame.h"
#include <qmessagebox.h>
#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>


NewGame::NewGame(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
	ui.stackedWidget->addWidget(&LoadGame_class);
}

NewGame::~NewGame()
{}



void NewGame::on_pushButton_confirm_next_page_clicked()
{
	ui.stackedWidget->setCurrentIndex(1);
}

void NewGame::on_pushButton_confirm_into_load_game_clicked()
{
	ui.stackedWidget->setCurrentIndex(2);
}