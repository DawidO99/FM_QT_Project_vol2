#include "playable_classes.h"
#include <iostream>

Player::Player(std::string name, int overall)
{
	this->name = name;
	this->overall = overall;
}

Team::Team(std::string team_name, std::string manager_name, std::string acronym, int overall, int points)
{
	this->name = team_name;
	this->manager = manager_name;
	this->acronym = acronym;
	this->overall = overall;
	this->points = points;
}

std::string Team::get_manager(Team T)
{
	return T.manager;
}
std::string Team::get_acronym(Team T)
{
	return T.acronym;
}
int Team::get_overall(Team T)
{
	return T.overall;
}