#include "NewGame.h"
#include <qmessagebox.h>
#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <fstream>
#include <filesystem>


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
	std::string file_name = "saves/" + ui.textEdit_save_name->toPlainText().toStdString() + ".txt";
	if (!std::filesystem::exists(file_name))
	{
		make_save();
		ui.stackedWidget->setCurrentIndex(1);
	}
	//except : taki plik juz istnieje
}

void NewGame::on_pushButton_confirm_into_load_game_clicked()
{
	pick_players();
	ui.stackedWidget->setCurrentIndex(2);
}

void NewGame::make_save()
{
	std::string file_name = "saves/" + ui.textEdit_save_name->toPlainText().toStdString() + ".txt";
	std::string player_name = ui.textEdit_player_name->toPlainText().toStdString();
	std::string team_name = ui.textEdit_team_name->toPlainText().toStdString();
	std::string team_acronym = ui.textEdit_team_acronym->toPlainText().toStdString();
	std::string line;
	std::fstream save_file(file_name, std::ios::app);
	std::ifstream teams_file("files/teams.txt");
	if (save_file && teams_file)
	{
		while (std::getline(teams_file, line))
			save_file << line << std::endl;
	}
	teams_file.close();
	if (save_file.good())
	{
		save_file << team_name << std::endl;
		save_file << player_name << std::endl;
		save_file << team_acronym << std::endl;
	}
	save_file.close();
	std::string my_team_name = "saves/" + ui.textEdit_save_name->toPlainText().toStdString() + "MyTeam.txt";
	std::fstream my_team(my_team_name, std::ios::app);
	if (my_team.good())
	{
		my_team << team_name << std::endl;
		my_team << player_name << std::endl;
		my_team << team_acronym << std::endl;
	}
	my_team.close();
}

void NewGame::pick_players()
{
	int ovr_sum = 0;
	
	QString help = ui.comboBox_goalkeeper->currentText();
	QStringList parts = help.split("-");
	QString name = parts[0].trimmed();
	QString num = parts[1].trimmed();
	std::string gk = name.toStdString();
	int gk_ovr = num.toInt();
	ovr_sum += gk_ovr;

	help = ui.comboBox_right_back->currentText();
	parts = help.split("-");
	name = parts[0].trimmed();
	num = parts[1].trimmed();
	std::string rb = name.toStdString();
	int rb_ovr = num.toInt();
	ovr_sum += rb_ovr;

	help = ui.comboBox_center_back_2->currentText();
	parts = help.split("-");
	name = parts[0].trimmed();
	num = parts[1].trimmed();
	std::string rcb = name.toStdString();
	int rcb_ovr = num.toInt();
	ovr_sum += rcb_ovr;

	help = ui.comboBox_center_back_1->currentText();
	parts = help.split("-");
	name = parts[0].trimmed();
	num = parts[1].trimmed();
	std::string lcb = name.toStdString();
	int lcb_ovr = num.toInt();
	ovr_sum += lcb_ovr;

	help = ui.comboBox_left_back->currentText();
	parts = help.split("-");
	name = parts[0].trimmed();
	num = parts[1].trimmed();
	std::string lb = name.toStdString();
	int lb_ovr = num.toInt();
	ovr_sum += lb_ovr;

	help = ui.comboBox_defensive_midfielder_2->currentText();
	parts = help.split("-");
	name = parts[0].trimmed();
	num = parts[1].trimmed();
	std::string rcdm = name.toStdString();
	int rcdm_ovr = num.toInt();
	ovr_sum += rcdm_ovr;
	
	help = ui.comboBox_defensive_midfielder_1->currentText();
	parts = help.split("-");
	name = parts[0].trimmed();
	num = parts[1].trimmed();
	std::string lcdm = name.toStdString();
	int lcdm_ovr = num.toInt();
	ovr_sum += lcdm_ovr;

	help = ui.comboBox_right_forward->currentText();
	parts = help.split("-");
	name = parts[0].trimmed();
	num = parts[1].trimmed();
	std::string rw = name.toStdString();
	int rw_ovr = num.toInt();
	ovr_sum += rw_ovr;

	help = ui.comboBox_offensive_midfielder->currentText();
	parts = help.split("-");
	name = parts[0].trimmed();
	num = parts[1].trimmed();
	std::string cam = name.toStdString();
	int cam_ovr = num.toInt();
	ovr_sum += cam_ovr;

	help = ui.comboBox_left_forward->currentText();
	parts = help.split("-");
	name = parts[0].trimmed();
	num = parts[1].trimmed();
	std::string lw = name.toStdString();
	int lw_ovr = num.toInt();
	ovr_sum += lw_ovr;

	help = ui.comboBox_center_forward->currentText();
	parts = help.split("-");
	name = parts[0].trimmed();
	num = parts[1].trimmed();
	std::string st = name.toStdString();
	int st_ovr = num.toInt();
	ovr_sum += st_ovr;

	ovr_sum /= 11;
	std::string file_name = "saves/" + ui.textEdit_save_name->toPlainText().toStdString() + ".txt";
	std::fstream save_file(file_name, std::ios::app);
	if (save_file.good())
	{
		save_file << ovr_sum;
		save_file << std::endl;
		
		save_file << "$";
		save_file << std::endl;

		save_file << gk << std::endl;
		save_file << gk_ovr << std::endl;
		save_file << rb << std::endl;
		save_file << rb_ovr << std::endl;
		save_file << rcb << std::endl;
		save_file << rcb_ovr << std::endl;
		save_file << lcb << std::endl;
		save_file << lcb_ovr << std::endl;
		save_file << lb << std::endl;
		save_file << lb_ovr << std::endl;
		save_file << rcdm << std::endl;
		save_file << rcdm_ovr << std::endl;
		save_file << lcdm << std::endl;
		save_file << lcdm_ovr << std::endl;
		save_file << rw << std::endl;
		save_file << rw_ovr << std::endl;
		save_file << cam << std::endl;
		save_file << cam_ovr << std::endl;
		save_file << lw << std::endl;
		save_file << lw_ovr << std::endl;
		save_file << st << std::endl;
		save_file << st_ovr << std::endl;

		save_file << "$" << std::endl;
	}
	save_file.close();
	std::string my_team_name = "saves/" + ui.textEdit_save_name->toPlainText().toStdString() + "MyTeam.txt";
	std::fstream my_team(my_team_name, std::ios::app);
	if (my_team.good())
		my_team << ovr_sum;
	my_team.close();
}
