#ifndef MATCHSIMULATION_H
#define MATCHSIMULATION_H

#include "Match.h"

class MatchSimulation
{
private:

    Match *match;

    int totalovers;

    Team *battingTeam;
    Team *bowlingTeam;

    PlayingXI *battingXI;
    PlayingXI *bowlingXI;

    PlayingNode *strikerNode;
    PlayingNode *nonStrikerNode;
    PlayingNode *nextBatsmanNode;
    PlayingNode *bowlerNode;

    Player *Striker;
    Player *nonStriker;
    Player *currentBowler;

    int runs;
    int wickets;
    int currentover;
    int balls;

    int target;

    // First innings
    int firstInningsRuns;
    int firstInningsWickets;
    Team *firstBattingTeam;

    // Second innings
    int secondInningsRuns;
    int secondInningsWickets;
    Team *secondBattingTeam;

public:

    MatchSimulation(Match *match);

    void startMatch();
    void toss();

    void simulateInnings();
    void simulateBall();

    void resetInnings();

    void displayResult();
};

#endif