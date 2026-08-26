#ifndef PLAYERMANAGEMENT_H
#define PLAYERMANAGEMENT_H
#include <string>
using namespace std;
struct Player
{
    int playerID;
    int teamID;
    string playerName;
    string teamName;
    int age;
    int jerseyNo;
    string role;
    int battingRating;
    int bowlingRating;
    int runs;
    int ballsFaced;
    int fours;
    int sixes;
    int wickets;
    int runsConceded;
    Player *next;
};

void addPlayer();
void displayPlayers();
void searchPlayer();
void deletePlayer();
void displayPlayersByTeam();
Player *getPlayerHead();
#endif