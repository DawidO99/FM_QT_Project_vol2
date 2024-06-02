#pragma once

#include <QMainWindow>
#include "ui_LoadGame.h"
#include "CustomCalendarWidget.h"
#include "playable_classes.h"

class LoadGame : public QMainWindow
{
	Q_OBJECT

public:
	LoadGame(QWidget *parent = nullptr);
	~LoadGame();
	void load_save();
	int week = 1;

private:
	Ui::LoadGameClass ui;
	CustomCalendarWidget* customCalendar;
	std::vector<Player>squad;
	std::vector<Team>league;

private slots:
	void on_pushButton_schedule_clicked();
	void on_pushButton_table_clicked();
	void on_pushButton_confirm_next_page_clicked();
	void on_pushButton_exit_clicked();
	void on_pushButton_save_clicked();
	void on_pushButton_team_clicked();
	void on_pushButton_go_back_clicked();
	void on_pushButton_play_clicked();
};
