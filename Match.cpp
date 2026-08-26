#include <iostream>
#include "Match.h"
#include "BestX1.h"

using namespace std;
Match::Match(int team1ID, int team2ID)
{
    team1 = getTeamByID(team1ID);
    team2 = getTeamByID(team2ID);
}
void Match::generatePlayingXIs()
{
    if(team1 == nullptr || team2 == nullptr)
    {
        cout << "Invalid Team ." <<endl;
        return;
    }
    predictBestX1(team1->TeamID, team1XI);
    predictBestX1(team2->TeamID, team2XI);
}
void Match::displayDashboard()
{
    cout << "\n========================================" << endl;
    cout << "           MATCH DASHBOARD" << endl;
    cout << "========================================" << endl;

    cout << "\n" << team1->TeamName
         << "  VS  "
         << team2->TeamName << endl;

    cout << "\n----------------------------------------" << endl;
    cout << team1->TeamName << " PLAYING XI" << endl;
    cout << "----------------------------------------" << endl;

    team1XI.display();

    cout << "\n----------------------------------------" << endl;
    cout << team2->TeamName << " PLAYING XI" << endl;
    cout << "----------------------------------------" << endl;

    team2XI.display();

    cout << "\n========================================" << endl;
}