#include "LoadGame.h"
#include <QApplication>
#include <fstream>
#include <sstream>
#include <cmath>
#include <qmessagebox.h>


LoadGame::LoadGame(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
	ui.stackedWidget_content->setCurrentIndex(2);
	srand(time(NULL));
}

LoadGame::~LoadGame()
{}

void LoadGame::on_pushButton_exit_clicked()
{
	//some shit
	exit(0);
}
void LoadGame::on_pushButton_team_clicked()
{
	std::string file_name = "saves/" + ui.textEdit_file_name->toPlainText().toStdString() + ".txt";
	std::ifstream my_team(file_name);
	std::string line;
	std::string player;
	int overall;
	std::string output;

	while (my_team.is_open() && my_team.peek() != '$')
		std::getline(my_team, line);
	std::getline(my_team, line);
	while (my_team.is_open() && my_team.peek() != '#')
	{
		if (my_team.peek() == '$')
			break;
		std::getline(my_team, player);
		my_team >> overall;
		output = player + "-" + std::to_string(overall);
		QString final_output = QString::fromStdString(output);
		ui.label_goalkeeper->setText(final_output);
		std::getline(my_team, line);

		if (my_team.peek() == '$')
			break;
		std::getline(my_team, player);
		my_team >> overall;
		output = player + "-" + std::to_string(overall);
		final_output = QString::fromStdString(output);
		ui.label_right_back->setText(final_output);
		std::getline(my_team, line);

		if (my_team.peek() == '$')
			break;
		std::getline(my_team, player);
		my_team >> overall;
		output = player + "-" + std::to_string(overall);
		final_output = QString::fromStdString(output);
		ui.label_2nd_center_back->setText(final_output);
		std::getline(my_team, line);

		if (my_team.peek() == '$')
			break;
		std::getline(my_team, player);
		my_team >> overall;
		output = player + "-" + std::to_string(overall);
		final_output = QString::fromStdString(output);
		ui.label_1st_center_back->setText(final_output);
		std::getline(my_team, line);

		if (my_team.peek() == '$')
			break;
		std::getline(my_team, player);
		my_team >> overall;
		output = player + "-" + std::to_string(overall);
		final_output = QString::fromStdString(output);
		ui.label_left_back->setText(final_output);
		std::getline(my_team, line);

		if (my_team.peek() == '$')
			break;
		std::getline(my_team, player);
		my_team >> overall;
		output = player + "-" + std::to_string(overall);
		final_output = QString::fromStdString(output);
		ui.label_right_def_midfielder->setText(final_output);
		std::getline(my_team, line);

		if (my_team.peek() == '$')
			break;
		std::getline(my_team, player);
		my_team >> overall;
		output = player + "-" + std::to_string(overall);
		final_output = QString::fromStdString(output);
		ui.label_left_def_midfielder->setText(final_output);
		std::getline(my_team, line);

		if (my_team.peek() == '$')
			break;
		std::getline(my_team, player);
		my_team >> overall;
		output = player + "-" + std::to_string(overall);
		final_output = QString::fromStdString(output);
		ui.label_right_forward->setText(final_output);
		std::getline(my_team, line);

		if (my_team.peek() == '$')
			break;
		std::getline(my_team, player);
		my_team >> overall;
		output = player + "-" + std::to_string(overall);
		final_output = QString::fromStdString(output);
		ui.label_offensive_midfielder->setText(final_output);
		std::getline(my_team, line);

		if (my_team.peek() == '$')
			break;
		std::getline(my_team, player);
		my_team >> overall;
		output = player + "-" + std::to_string(overall);
		final_output = QString::fromStdString(output);
		ui.label_left_forward->setText(final_output);
		std::getline(my_team, line);

		if (my_team.peek() == '$')
			break;
		std::getline(my_team, player);
		my_team >> overall;
		output = player + "-" + std::to_string(overall);
		final_output = QString::fromStdString(output);
		ui.label_center_forward->setText(final_output);
		std::getline(my_team, line);
	}
	ui.label_date->setText("Here you can view your team.");
	ui.stackedWidget_content->setCurrentIndex(1);
}

void LoadGame::on_pushButton_play_clicked()
{
	if (week <= 38)
	{
		std::string my_team_name = "saves/" + ui.textEdit_file_name->toPlainText().toStdString() + "MyTeam.txt";
		std::ifstream my_team_file(my_team_name);
		std::string my_team;
		std::getline(my_team_file, my_team);
		my_team_file.close();

		std::string matchday = "files/League_Schedule/Round_" + std::to_string(week);
		matchday += ".txt";
		std::ifstream matches(matchday);
		std::string team1;
		std::string team2;
		std::string line;
		std::string result;
		int goal1 = 0, goal2 = 0, ind1 = 0, ind2 = 0;
		int match = 0;

		std::string matchday_label = "Matchay " + std::to_string(week);
		QStringList headers;
		headers << QString::fromStdString(matchday_label);
		ui.tableWidget_matchday->setHorizontalHeaderLabels(headers);

		while (matches.good())
		{
			std::getline(matches, team1);
			if (team1 == "Nasz team")
				team1 = my_team;
			std::getline(matches, team2);
			if (team2 == "Nasz team")
				team2 = my_team;
			std::getline(matches, line);
			for (int i = 0; i < league.size(); i++)
			{
				if (league[i].name == team1)
				{
					goal1 = (((float)rand() / RAND_MAX) * league[i].get_overall(league[i])) / 15;
					ind1 = i;
				}
				if (league[i].name == team2)
				{
					goal2 = (((float)rand() / RAND_MAX) * league[i].get_overall(league[i])) / 15;
					ind2 = i;
				}
			}
			if (goal1 == goal2)
			{
				league[ind1].points++;
				league[ind2].points++;
			}
			else if (goal1 > goal2)
				league[ind1].points += 3;
			else
				league[ind2].points += 3;
			result = team1 + " " + std::to_string(goal1) + ":" + std::to_string(goal2) + " " + team2;
			QString qresult = QString::fromStdString(result);
			QVariant casted(qresult);
			QTableWidgetItem* item = new QTableWidgetItem();
			item->setData(Qt::DisplayRole, casted);
			ui.tableWidget_matchday->setItem(match, 0, item);
			match++;
		}
		week++;
		ui.stackedWidget->setCurrentIndex(2);
	}
	else
	{
		std::string my_team_name = "saves/" + ui.textEdit_file_name->toPlainText().toStdString() + "MyTeam.txt";
		std::ifstream my_team_file(my_team_name);
		std::string my_team;
		std::getline(my_team_file, my_team);
		my_team_file.close();
		for (int i = 0; i < league.size(); i++)
		{
			if (league[i].name == my_team)
			{
				QString place = QString::fromStdString(std::to_string(i + 1));
				QString text = "Congratulations! You finished in " + place;
				text+=" place.";
				ui.label_date->setText(text);
			}
		}
		
		
	}
	
}

void LoadGame::on_pushButton_go_back_clicked()
{
	ui.label_date->setText("The match is over.");
	ui.stackedWidget->setCurrentIndex(1);
	ui.stackedWidget_content->setCurrentIndex(2);
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
	ui.label_date->setText("Current league standings.");
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
	QString if_empty = ui.textEdit_file_name->toPlainText();
	if (if_empty.isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setWindowTitle("Save name error");
		msgBox.setText("Save name cannot be empty.");
		msgBox.setInformativeText("Please, choose a different save name.");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setStyleSheet(
			"QMessageBox { background-color: #32CD32; border: 1px solid #228B22; }"
			"QLabel { color: white; }"
			"QPushButton { background-color: #32CD32; color:white; border: none; padding: 5px 10px; }"
			"QPushButton:hover { background-color: #228B22; }"
		);
		msgBox.exec();
		return;
	}
	std::string file_name = "saves/" + ui.textEdit_file_name->toPlainText().toStdString() + ".txt";
	std::ifstream check_file(file_name);
	if (check_file.good())
	{
		load_save();
		ui.stackedWidget->setCurrentIndex(1);
		ui.label_date->setText("What's up coach?");
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setWindowTitle("File open error");
		msgBox.setText("Provided save doesn't exist");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setStyleSheet(
			"QMessageBox { background-color: #32CD32; border: 1px solid #228B22; }"
			"QLabel { color: white; }"
			"QPushButton { background-color: #32CD32; color:white; border: none; padding: 5px 10px; }"
			"QPushButton:hover { background-color: #228B22; }"
		);
		msgBox.exec();
	}
}

void LoadGame::on_pushButton_save_clicked()
{
	std::string original_file = "saves/" + ui.textEdit_file_name->toPlainText().toStdString() + ".txt";
	std::fstream file(original_file, std::ios::in | std::ios::out);
	std::string line;
	int num;
	file.clear();
	for (int i = 0; i < league.size(); i++)
	{
		line = league[i].name;
		file << line << std::endl;
		line = league[i].get_manager(league[i]);
		file << line << std::endl;
		line = league[i].get_acronym(league[i]);
		file << line << std::endl;
		num = league[i].get_overall(league[i]);
		file << num << std::endl;
		num = league[i].points;
		file << num << std::endl;
	}
	file << '$' << std::endl;
	for (int i = 0; i < squad.size(); i++)
	{
		line = squad[i].name;
		file << line << std::endl;
		num = squad[i].overall;
		file << num << std::endl;
	}
	file << '#' << std::endl;
	file << week << std::endl;
	file << '$' << std::endl;
	file.close();
	ui.label_date->setText("Your game has been saved.");
}

void LoadGame::load_save()
{
	std::string file_name = "saves/" + ui.textEdit_file_name->toPlainText().toStdString() + ".txt";
	std::fstream load_file(file_name, std::ios::in);
	std::string player, team, acronym, line;
	int overall, points;

	while(load_file.is_open() && load_file.peek() != '$')
	{
		std::getline(load_file, team);
		std::getline(load_file, player);
		std::getline(load_file, acronym);
		load_file >> overall;
		std::getline(load_file, line);
		load_file >> points;
		std::getline(load_file, line);
		Team T(team, player, acronym, overall, points);
		league.push_back(T);
	}

	std::getline(load_file, line);
	while (load_file.is_open() && load_file.peek() != '#')
	{
		std::getline(load_file, player);
		load_file >> overall;
		std::getline(load_file, line);
		Player P(player, overall);
		squad.push_back(P);
	}

	std::string original_file = "saves/" + ui.textEdit_file_name->toPlainText().toStdString() + ".txt";
	std::ifstream which_week(original_file);
	while (which_week.peek() != '#')
		std::getline(which_week, line);
	std::getline(which_week, line);
	which_week >> week;
	which_week.close();
}