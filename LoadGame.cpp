#include "LoadGame.h"
#include <QApplication>
#include <fstream>


LoadGame::LoadGame(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
}

LoadGame::~LoadGame()
{}

void LoadGame::on_pushButton_schedule_clicked()
{
	ui.stackedWidget_content->setCurrentIndex(1);
	//random tests
	int possiblepoints[3] = { 0,1,3 };
	for (int i = 0; i < league.size(); i++)
		league[i].points += possiblepoints[rand() % 3];
}

void LoadGame::on_pushButton_table_clicked()
{
	std::string my_team_name = "saves/" + ui.textEdit_file_name->toPlainText().toStdString() + "MyTeam.txt";
	std::ifstream my_team(my_team_name);
	std::string my_name;
	if(my_team.good())
		std::getline(my_team, my_name);
	my_team.close();
	ui.stackedWidget_content->setCurrentIndex(0);
	sort(league.begin(), league.end());
	for (int i = 0; i < league.size(); i++)
	{
		QString team_name = QString::fromStdString(league[i].name);
		QVariant casted(team_name);
		QTableWidgetItem* item = new QTableWidgetItem();
		item->setData(Qt::DisplayRole, casted);
		ui.tableWidget->setItem(i, 0, item);
		if(league[i].name == my_name)
			ui.tableWidget->item(i, 0)->setBackground(Qt::red);
		
		QString points = QString::number(league[i].points);
		QVariant casted2(points);
		QTableWidgetItem* item2 = new QTableWidgetItem();
		item2->setData(Qt::DisplayRole, casted2);
		ui.tableWidget->setItem(i, 1, item2);
	}
}

void LoadGame::on_pushButton_confirm_next_page_clicked()
{
	std::string file_name = "saves/" + ui.textEdit_file_name->toPlainText().toStdString() + ".txt";
	std::ifstream check_file(file_name);
	if (check_file.good())
	{
		load_save();
		ui.stackedWidget->setCurrentIndex(1);
	}
	//jaki except
}

void LoadGame::load_save()
{
	std::string file_name = "saves/" + ui.textEdit_file_name->toPlainText().toStdString() + ".txt";
	//tu chyba tez by sie przydalo cos
	std::fstream load_file(file_name, std::ios::in);

	std::string player, team, acronym, line;
	int overall;
	while(load_file.is_open() && load_file.peek() != '$')
	{
		std::getline(load_file, team);
		std::getline(load_file, player);
		std::getline(load_file, acronym);
		load_file >> overall;
		std::getline(load_file, line);
		Team T(team, player, acronym, overall, 0);
		league.push_back(T);
	}
	//tu jakis except
	std::getline(load_file, line);
	while (load_file.is_open() && load_file.peek() != '$')
	{
		std::getline(load_file, player);
		load_file >> overall;
		std::getline(load_file, line);
		Player P(player, overall);
		squad.push_back(P);
	}
	//tu jakis except
}