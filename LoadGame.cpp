#include "LoadGame.h"
#include <QApplication>


LoadGame::LoadGame(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);

}

LoadGame::~LoadGame()
{}

void LoadGame::on_pushButton_schedule_clicked()
{
	ui.stackedWidget_content->setCurrentIndex(1);
}

void LoadGame::on_pushButton_table_clicked()
{
	ui.stackedWidget_content->setCurrentIndex(0);
}

void LoadGame::on_pushButton_confirm_next_page_clicked()
{
	ui.stackedWidget->setCurrentIndex(1);
}
