#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StartScreen.h"
#include "NewGame.h"
#include "LoadGame.h"

class StartScreen : public QMainWindow
{
    Q_OBJECT

public:
    StartScreen(QWidget *parent = nullptr);
    ~StartScreen();

private:
    Ui::StartScreenClass ui;
    NewGame NewGame_class;
    LoadGame LoadGame_class;
private slots:
    void on_pushButton_start_game_clicked();
    void on_pushButton_load_game_clicked();
};
