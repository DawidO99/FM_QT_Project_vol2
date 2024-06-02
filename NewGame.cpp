#include "NewGame.h"
#include <qmessagebox.h>
#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <fstream>
#include <filesystem>

NewGame::NewGame(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
	ui.stackedWidget->addWidget(&LoadGame_class);
	textEdit_player_name = findChild<QTextEdit*>("textEdit_player_name");
	textEdit_save_name = findChild<QTextEdit*>("textEdit_save_name");
	textEdit_team_acronym = findChild<QTextEdit*>("textEdit_team_acronym");
	textEdit_team_name = findChild<QTextEdit*>("textEdit_team_name");

	textEdit_player_name->installEventFilter(this);
	textEdit_save_name->installEventFilter(this);
	textEdit_team_acronym->installEventFilter(this);
	textEdit_team_name->installEventFilter(this);
}

NewGame::~NewGame()
{}


bool NewGame::eventFilter(QObject* obj, QEvent* event)
{
	// Sprawdzenie, czy zdarzenie to naciœniêcie klawisza
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
		// Sprawdzenie, czy naciœniêto klawisz Enter
		if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
			// Jeœli naciœniêto Enter w textEdit_player_name, przenieœ focus do textEdit_save_name
			if (obj == textEdit_save_name) {
				textEdit_player_name->setFocus();
				return true; // Zwrócenie true oznacza, ¿e zdarzenie zosta³o obs³u¿one
			}
			if (obj == textEdit_player_name) {
				textEdit_team_name->setFocus();
				return true; // Zwrócenie true oznacza, ¿e zdarzenie zosta³o obs³u¿one
			}
			if (obj == textEdit_team_name) {
				textEdit_team_acronym->setFocus();
				return true; // Zwrócenie true oznacza, ¿e zdarzenie zosta³o obs³u¿one
			}
			if (obj == textEdit_team_acronym) {
				textEdit_team_acronym->setFocus();
				return true; // Zwrócenie true oznacza, ¿e zdarzenie zosta³o obs³u¿one
			}
		}
	}
	// Przekazanie zdarzenia do standardowego przetwarzania
	return QMainWindow::eventFilter(obj, event);
}

void NewGame::on_pushButton_confirm_next_page_clicked()
{
	std::string file_name = "saves/" + ui.textEdit_save_name->toPlainText().toStdString() + ".txt";
	QString if_empty = ui.textEdit_save_name->toPlainText();
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
	if (!std::filesystem::exists(file_name))
	{
		make_save();
		ui.stackedWidget->setCurrentIndex(1);
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setWindowTitle("Save error");
		msgBox.setText("Such a file already exists");
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
	}
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
	else
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setWindowTitle("File open error");
		msgBox.setText("Can't open the file");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setStyleSheet(
			"QMessageBox { background-color: #32CD32; border: 1px solid #228B22; }"
			"QLabel { color: white; }"
			"QPushButton { background-color: #32CD32; color:white; border: none; padding: 5px 10px; }"
			"QPushButton:hover { background-color: #228B22; }"
		);
		msgBox.exec();
		exit(0);
	}
	teams_file.close();
	if (save_file.good())
	{
		save_file << team_name << std::endl;
		save_file << player_name << std::endl;
		save_file << team_acronym << std::endl;
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setWindowTitle("File open error");
		msgBox.setText("Can't open the file");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setStyleSheet(
			"QMessageBox { background-color: #32CD32; border: 1px solid #228B22; }"
			"QLabel { color: white; }"
			"QPushButton { background-color: #32CD32; color:white; border: none; padding: 5px 10px; }"
			"QPushButton:hover { background-color: #228B22; }"
		);
		msgBox.exec();
		exit(0);
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
	else
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setWindowTitle("File open error");
		msgBox.setText("Can't open the file");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setStyleSheet(
			"QMessageBox { background-color: #32CD32; border: 1px solid #228B22; }"
			"QLabel { color: white; }"
			"QPushButton { background-color: #32CD32; color:white; border: none; padding: 5px 10px; }"
			"QPushButton:hover { background-color: #228B22; }"
		);
		msgBox.exec();
		exit(0);
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

	int points = 0;
	ovr_sum /= 11;
	std::string file_name = "saves/" + ui.textEdit_save_name->toPlainText().toStdString() + ".txt";
	std::fstream save_file(file_name, std::ios::app);
	if (save_file.good())
	{
		save_file << ovr_sum;
		save_file << std::endl;
		save_file << points;
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

		save_file << '#' << std::endl;
		save_file << 1 << std::endl;
		save_file << '$' << std::endl;
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setWindowTitle("File open error");
		msgBox.setText("Can't open the file");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setStyleSheet(
			"QMessageBox { background-color: #32CD32; border: 1px solid #228B22; }"
			"QLabel { color: white; }"
			"QPushButton { background-color: #32CD32; color:white; border: none; padding: 5px 10px; }"
			"QPushButton:hover { background-color: #228B22; }"
		);
		msgBox.exec();
		exit(0);
	}
	save_file.close();
	std::string my_team_name = "saves/" + ui.textEdit_save_name->toPlainText().toStdString() + "MyTeam.txt";
	std::fstream my_team(my_team_name, std::ios::app);
	if (my_team.good())
		my_team << ovr_sum;
	my_team.close();
}
