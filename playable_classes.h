#include <iostream>
#include <vector>

class Player
{
public:
    std::string name;
    int overall;
    Player(std::string name, int overall);
};


class Team 
{
private:
    std::string manager;
    std::string acronym;
    int overall;
public:
    Team(std::string team_name, std::string manager_name,
        std::string acronym, int overall, int points);
    std::string name;
    int points;
    bool operator<(const  Team& other)
    {
        return points > other.points;
    }
    std::string get_manager(Team T);
    std::string get_acronym(Team T);
    int get_overall(Team T);
};

