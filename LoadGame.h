#pragma once

#include <QMainWindow>
#include "ui_LoadGame.h"
#include "CustomCalendarWidget.h"

class LoadGame : public QMainWindow
{
	Q_OBJECT

public:
	LoadGame(QWidget *parent = nullptr);
	~LoadGame();

private:
	Ui::LoadGameClass ui;
	CustomCalendarWidget* customCalendar;

private slots:
	void on_pushButton_schedule_clicked();
	void on_pushButton_table_clicked();
	void on_pushButton_confirm_next_page_clicked();
};
