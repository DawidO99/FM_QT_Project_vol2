#pragma once

#include <QMainWindow>
#include "ui_NewGame.h"
#include "LoadGame.h"
#include <QTextEdit>
#include <QKeyEvent>


class NewGame : public QMainWindow
{
	Q_OBJECT

public:
	NewGame(QWidget *parent = nullptr);
	~NewGame();
	
	void make_save();
	void pick_players();

	
private:
	Ui::NewGameClass ui;
	LoadGame LoadGame_class;
	QTextEdit* textEdit_player_name;
	QTextEdit* textEdit_save_name;
	QTextEdit* textEdit_team_acronym;
	QTextEdit* textEdit_team_name;

private slots:
	void on_pushButton_confirm_next_page_clicked();
	void on_pushButton_confirm_into_load_game_clicked();
protected:
	bool eventFilter(QObject* obj, QEvent* event) override;

};
