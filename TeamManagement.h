#ifndef TEAMMANAGEMENT_H
#define TEAMMANAGEMENT_H

#include <string>
using namespace std;

struct Team
{
    int TeamID;
    string TeamName;
    string captain;
    string coach;
    string city;

    int matchesPlayed;
    int matchesWon;
    int matchedLost;
    int points;

    Team *next;
};

bool checkID(int id);
Team* getTeamByID(int id);

void addTeam();
void displayTeams();
void searchTeam();
void updateTeam();
void deleteTeam();

#endif