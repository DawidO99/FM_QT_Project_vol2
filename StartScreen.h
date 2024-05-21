#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StartScreen.h"

class StartScreen : public QMainWindow
{
    Q_OBJECT

public:
    StartScreen(QWidget *parent = nullptr);
    ~StartScreen();

private:
    Ui::StartScreenClass ui;
};
