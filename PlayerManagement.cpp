#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "TeamManagement.h"
#include "PlayerManagement.h"
using namespace std;

Player *head = nullptr;
Player* createPlayer()
{
    Player *newPlayer = new Player;
    newPlayer->playerID = 0;
    newPlayer->teamID = 0;
    newPlayer->playerName = "";
    newPlayer->teamName = "";
    newPlayer->age = 0;
    newPlayer->jerseyNo = 0;
    newPlayer->role = "";
    newPlayer->battingRating = 0;
    newPlayer->bowlingRating = 0;
    newPlayer->runs = 0;
    newPlayer->ballsFaced = 0;
    newPlayer->fours = 0;
    newPlayer->sixes = 0;
    newPlayer->wickets = 0;
    newPlayer->runsConceded = 0;
    newPlayer->next = nullptr;
    return newPlayer;
}
Player *getPlayerHead()
{
    return head;
}
bool checkPlayerID(int id)
{
    ifstream file("Player.csv");
    if(!file)
    {
        cout << "Error opening Player.csv file." << endl;
        return false;
    }
    string line;
    getline(file,line);
    while(getline(file,line))
    {
    stringstream ss(line);
    string ids;
    getline(ss,ids,',');
    
    if(stoi(ids) == id)
    {
        return true;
    }
    }
    file.close();
    return false;
    
}
bool isPlayerAssigned(int id)
{
    Player *temp = head;
    while(temp != nullptr)
    {
        if(temp->playerID == id)
        {
            return true;
        }
        temp =temp->next;
    }
    return false;
}
bool loadPlayerDetails(int id,int teamID, Player *player)
{
    ifstream file("Player.csv");
    if(!file)
    {
        cout << "Error opening Player.csv file." << endl;
        return false;
    }
    string line;
    getline(file, line);
    while(getline(file,line))
    {
        stringstream ss(line);
        string playerID;
        string playerName;
        string age;
        string jerseyNo;
        string role;
        string battingRating;
        string bowlingRating;
        getline(ss, playerID, ',');
        getline(ss, playerName, ',');
        getline(ss, age, ',');
        getline(ss, jerseyNo, ',');
        getline(ss, role, ',');
        getline(ss, battingRating, ',');
        getline(ss, bowlingRating, ',');
        if(stoi(playerID) == id)
        {
            player->playerID = stoi(playerID);
            player->teamID = teamID;
            player->playerName = playerName;
            player->age = stoi(age);
            player->jerseyNo = stoi(jerseyNo);
            player->role = role;
            player->battingRating = stoi(battingRating);
            player->bowlingRating = stoi(bowlingRating);
            file.close();
            return true;
        }
    }
        file.close();
        return false;
    
}
void saveTeamPlayer(int teamID, int playerID)
{
    ofstream file("team_players.csv", ios::app);
    if(!file)
    {
        cout << "Error in Opening a File " << endl;
        return;
    }
    file << teamID<< "," <<playerID << endl;
    file.close();
}
void addPlayer()
{
    cout << "Enter Team ID for the Player: ";
    int teamID;
    cin >> teamID;
    while(!checkID(teamID))
    {
        cout << "Team with ID " << teamID << " does not exist. Please enter a valid Team ID: ";
        cin >> teamID;
    }

    Team *team = getTeamByID(teamID);
    if(team == nullptr)
    {
        cout << "Could not Find Team Name .";
        return;
    }
    
    cout << "Enter Player ID: ";
    int playerID;
    cin >> playerID;
    if(!checkPlayerID(playerID))
    {
         cout << "Player ID does not exist in Player.csv." << endl;
         return;       
    }
    if(isPlayerAssigned(playerID))
    {
        cout << "Player is Already Assigned to a team ." << endl;
        return ;
    }
    Player *newPlayer = createPlayer();    
    if(!loadPlayerDetails(playerID, teamID, newPlayer))
    {
        cout << "Loading player details failed" << endl;
        delete newPlayer;
        return;
    }
    newPlayer->teamName = team->TeamName;
    if(head == nullptr)
    {
        head= newPlayer;
    }
    else
    {
        Player *temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newPlayer;
    }
    cout << "Player added successfully." << endl;
    saveTeamPlayer(teamID,playerID);

}

void displayPlayers()
{
    if(head == nullptr)
    {
        cout << "No Players to Display .";
        return;
    }
    Player *temp = head;
    cout << "------------------------------------------" << endl;
    while(temp != nullptr)
    {
        cout << "Player Name        : " << temp->playerName << endl;
        cout << "Player ID          : " << temp->playerID << endl;
        cout << "Team ID            : " << temp->teamID << endl;
        cout << "TeamName           : " << temp->teamName << endl;
        cout << "Jersey Number      : " << temp->jerseyNo << endl;
        temp = temp->next;
    }
    cout << " -----------------------------------------" << endl;
}

void searchPlayer()
{
    int id;
    cout << "Enter the Player Id to search ";
    cin >> id;
    if(head == nullptr){
        cout << "Empty Player List ." << endl;
        return ;
    }
    Player *temp = head;
    while(temp != nullptr)
    {
        if(temp->playerID == id)
        {
            cout << "------------------------------------------" << endl;
            cout << "Player ID      : " << temp->playerID << endl;
            cout << "Player Name    : " << temp->playerName << endl;
            cout << "Team ID        : " << temp->teamID << endl;
            cout << "Team Name      : " << temp->teamName << endl;
            cout << "Age            : " << temp->age << endl;
            cout << "Jersey Number  : " << temp->jerseyNo << endl;
            cout << "Role           : " << temp->role << endl;
            cout << "Batting Rating : " << temp->battingRating << endl;
            cout << "Bowling Rating : " << temp->bowlingRating << endl;
            cout << "------------------------------------------" << endl;
            return;          
        }
        temp = temp->next;
    }
    cout << "Player with ID Dont Exsist ." << endl;
    
}
void deletePlayer()
{
    int id;
    cout << "Enter the player ID : " ;
    cin >> id;
    if(head == nullptr){
        cout << "Empty Player List ." << endl;
        return ;
    }
    if(head->playerID == id)
    {
        Player *del = head;
        head = head->next;
        delete del;
        cout << "Player Deleted Successully " << endl;
        return;
    }
    Player *prev = head;
    Player *temp = head->next;
    while(temp != nullptr)
    {
        if(temp->playerID == id)
        {
            prev->next =temp->next;
            delete temp;
            cout << "Player Deleted Successully " << endl;
            return;          
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Player with ID Dont Exsist " << endl;
}
void displayPlayersByTeam()
{
    int TeamID;
    cout << "Enter the Team Id : ";
    cin >> TeamID;
    if(!checkID(TeamID))
    {
        cout << "Team ID is Invalid " << endl;
        return;
    }
    Player *temp = head;
    Team *team = getTeamByID(TeamID);
    bool found = false;
 
    cout << "-----------------------------------" << endl;
    cout << " TEAM NAME     : " << team->TeamName << endl;
    while(temp != nullptr)
    {
        if(temp->teamID == TeamID)
        {    
            cout << "Player Name     : " <<temp->playerName << endl;
            cout << "Player Id       : " <<temp->playerID << endl;
            cout << endl;
            found = true;
        }
        temp = temp->next;
    }
    if(!found)
    {
        cout << "Players Had Not Assigned Yet " << endl;

    }
    cout << "-----------------------------------" << endl;
}

