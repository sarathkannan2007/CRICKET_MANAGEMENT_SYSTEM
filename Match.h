#ifndef MATCH_H
#define MATCH_H

#include "TeamManagement.h"
#include "PlayingXI.h"

class Match
{
    private :
        Team *team1;
        Team *team2;
        PlayingXI team1XI;
        PlayingXI team2XI;
    public  :
        Match(int team1ID, int team2ID);
        void generatePlayingXIs();
        void displayDashboard();
        Team *getTeam1();
        Team *getTeam2();
        PlayingXI* getTeam1XI();
        PlayingXI* getTeam2XI();
};

#endif