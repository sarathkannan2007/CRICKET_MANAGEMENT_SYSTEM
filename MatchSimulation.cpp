#include <iostream>
#include <cstdlib>
#include <ctime>

#include "MatchSimulation.h"

using namespace std;


MatchSimulation::MatchSimulation(Match *match)
{
    this->match = match;

    totalovers = 2;

    battingTeam = nullptr;
    bowlingTeam = nullptr;

    battingXI = nullptr;
    bowlingXI = nullptr;

    strikerNode = nullptr;
    nonStrikerNode = nullptr;
    nextBatsmanNode = nullptr;
    bowlerNode = nullptr;

    Striker = nullptr;
    nonStriker = nullptr;
    currentBowler = nullptr;

    runs = 0;
    wickets = 0;
    currentover = 0;
    balls = 0;

    target = -1;

    firstInningsRuns = 0;
    firstInningsWickets = 0;
    firstBattingTeam = nullptr;

    secondInningsRuns = 0;
    secondInningsWickets = 0;
    secondBattingTeam = nullptr;
}




void MatchSimulation::startMatch()
{
    srand(time(0));

    cout << "\n========================================" << endl;
    cout << "             MATCH START" << endl;
    cout << "========================================" << endl;

    cout << "\n"
         << match->getTeam1()->TeamName
         << " VS "
         << match->getTeam2()->TeamName
         << endl;

    // Toss
    toss();



    simulateInnings();

    firstInningsRuns = runs;
    firstInningsWickets = wickets;
    firstBattingTeam = battingTeam;

    cout << "\n========================================" << endl;
    cout << "          END OF FIRST INNINGS" << endl;
    cout << "========================================" << endl;

    cout << firstBattingTeam->TeamName
         << " : "
         << firstInningsRuns
         << "/"
         << firstInningsWickets
         << endl;

    cout << "Overs : "
         << currentover
         << "."
         << balls
         << endl;




    Team *tempTeam = battingTeam;

    battingTeam = bowlingTeam;
    bowlingTeam = tempTeam;

    secondBattingTeam = battingTeam;

    target = firstInningsRuns + 1;

    resetInnings();




    cout << "\n========================================" << endl;
    cout << "          SECOND INNINGS" << endl;
    cout << "========================================" << endl;

    cout << secondBattingTeam->TeamName
         << " needs "
         << target
         << " runs to win."
         << endl;

    simulateInnings();

    secondInningsRuns = runs;
    secondInningsWickets = wickets;


 

    displayResult();
}

void MatchSimulation::toss()
{
    int tossResult = rand() % 2;

    Team *tossWinner;

    if(tossResult == 0)
    {
        tossWinner = match->getTeam1();
    }
    else
    {
        tossWinner = match->getTeam2();
    }


    cout << "\nToss Winner : "
         << tossWinner->TeamName
         << endl;

    cout << "\n1. Bat" << endl;
    cout << "2. Bowl" << endl;

    int choice;

    cout << "Enter your Choice : ";
    cin >> choice;


    if(choice == 1)
    {
        cout << "\n"
             << tossWinner->TeamName
             << " chooses to Bat First."
             << endl;

        battingTeam = tossWinner;

        if(tossWinner == match->getTeam1())
        {
            bowlingTeam = match->getTeam2();
        }
        else
        {
            bowlingTeam = match->getTeam1();
        }
    }

    else if(choice == 2)
    {
        cout << "\n"
             << tossWinner->TeamName
             << " chooses to Bowl First."
             << endl;

        bowlingTeam = tossWinner;

        if(tossWinner == match->getTeam1())
        {
            battingTeam = match->getTeam2();
        }
        else
        {
            battingTeam = match->getTeam1();
        }
    }

    else
    {
        cout << "Invalid Choice." << endl;

        // Default to batting

        battingTeam = tossWinner;

        if(tossWinner == match->getTeam1())
        {
            bowlingTeam = match->getTeam2();
        }
        else
        {
            bowlingTeam = match->getTeam1();
        }
    }
}




void MatchSimulation::resetInnings()
{
    runs = 0;
    wickets = 0;

    currentover = 0;
    balls = 0;

    strikerNode = nullptr;
    nonStrikerNode = nullptr;
    nextBatsmanNode = nullptr;
    bowlerNode = nullptr;

    Striker = nullptr;
    nonStriker = nullptr;
    currentBowler = nullptr;
}



void MatchSimulation::simulateInnings()
{
    

    if(battingTeam == match->getTeam1())
    {
        battingXI = match->getTeam1XI();
        bowlingXI = match->getTeam2XI();
    }
    else
    {
        battingXI = match->getTeam2XI();
        bowlingXI = match->getTeam1XI();
    }


 

    strikerNode = battingXI->getHead();

    if(strikerNode == nullptr ||
       strikerNode->next == nullptr)
    {
        cout << "Invalid Batting XI." << endl;
        return;
    }

        bowlerNode = bowlingXI->getHead();

        while(bowlerNode != nullptr &&
              bowlerNode->player->role != "Bowler")
        {
              bowlerNode = bowlerNode->next;
        }

        if(bowlerNode == nullptr)
        {
             cout << "No Bowler Found in Playing XI." << endl;
             return;
        }
 

    nonStrikerNode = strikerNode->next;

    

    nextBatsmanNode = nonStrikerNode->next;


   

    Striker = strikerNode->player;

    nonStriker = nonStrikerNode->player;

    currentBowler = bowlerNode->player;


    cout << "\n----------------------------------------" << endl;

    cout << "Batting Team : "
         << battingTeam->TeamName
         << endl;

    cout << "Bowling Team : "
         << bowlingTeam->TeamName
         << endl;

    cout << "----------------------------------------" << endl;

    cout << "\nOpening Batsmen:" << endl;

    cout << "Striker : "
         << Striker->playerName
         << endl;

    cout << "Non-Striker : "
         << nonStriker->playerName
         << endl;

    cout << "Bowler : "
         << currentBowler->playerName
         << endl;


   

    while(currentover < totalovers &&
          wickets < 10)
    {
       
        if(target != -1 &&
           runs >= target)
        {
            break;
        }

        simulateBall();
    }


    cout << "\n----------------------------------------" << endl;
    cout << "INNINGS END" << endl;
    cout << "----------------------------------------" << endl;

    cout << battingTeam->TeamName
         << " : "
         << runs
         << "/"
         << wickets
         << endl;

    cout << "Overs : "
         << currentover
         << "."
         << balls
         << endl;
}



void MatchSimulation::simulateBall()
{
    if(Striker == nullptr ||
       nonStriker == nullptr ||
       currentBowler == nullptr)
    {
        return;
    }


    int outcome = rand() % 7;


    cout << "\n----------------------------------------" << endl;

    cout << "Ball "
         << currentover
         << "."
         << balls + 1
         << endl;

    cout << "Bowler  : "
         << currentBowler->playerName
         << endl;

    cout << "Striker : "
         << Striker->playerName
         << endl;




    Striker->ballsFaced++;



    if(outcome == 0)
    {
        cout << "Dot Ball!" << endl;
    }



    else if(outcome == 1)
    {
        runs++;

        Striker->runs++;
        currentBowler->runsConceded++;

        cout << Striker->playerName
             << " scores 1 run."
             << endl;



        Player *temp = Striker;

        Striker = nonStriker;
        nonStriker = temp;
    }


    else if(outcome == 2)
    {
        runs += 2;

        Striker->runs += 2;
        currentBowler->runsConceded += 2;

        cout << Striker->playerName
             << " scores 2 runs."
             << endl;
    }




    else if(outcome == 3)
    {
        runs += 3;

        Striker->runs += 3;
        currentBowler->runsConceded += 3;

        cout << Striker->playerName
             << " scores 3 runs."
             << endl;


 

        Player *temp = Striker;

        Striker = nonStriker;
        nonStriker = temp;
    }


  

    else if(outcome == 4)
    {
        runs += 4;

        Striker->runs += 4;
        Striker->fours++;

        currentBowler->runsConceded += 4;

        cout << Striker->playerName
             << " hits a FOUR!"
             << endl;
    }




    else if(outcome == 5)
    {
        runs += 6;

        Striker->runs += 6;
        Striker->sixes++;

        currentBowler->runsConceded += 6;

        cout << Striker->playerName
             << " hits a SIX!"
             << endl;
    }


    

    else
    {
        wickets++;

        currentBowler->wickets++;

        cout << Striker->playerName
             << " is OUT!"
             << endl;


        if(nextBatsmanNode != nullptr)
        {
            strikerNode = nextBatsmanNode;

            Striker = strikerNode->player;

            nextBatsmanNode = nextBatsmanNode->next;

            cout << "New Batsman : "
                 << Striker->playerName
                 << endl;
        }
    }




    balls++;




    if(balls == 6)
    {
        currentover++;

        balls = 0;

        cout << "\n*** OVER COMPLETED ***"
             << endl;

        cout << "Over : "
             << currentover
             << endl;



        Player *temp = Striker;

        Striker = nonStriker;
        nonStriker = temp;




        if(bowlerNode->next != nullptr)
        {
            bowlerNode = bowlerNode->next;

            currentBowler = bowlerNode->player;
        }
        else
        {
   

            bowlerNode = bowlingXI->getHead();

            while(bowlerNode != nullptr &&
            bowlerNode->player->role != "Bowler")
            {
                 bowlerNode = bowlerNode->next;
            }

            if(bowlerNode == nullptr)
            {
                cout << "No Bowler Found in Playing XI." << endl;
                return;
            }

            currentBowler = bowlerNode->player;
        }


        cout << "New Bowler : "
             << currentBowler->playerName
             << endl;
    }



    cout << "\nScore : "
         << runs
         << "/"
         << wickets
         << endl;

    cout << "Overs : "
         << currentover
         << "."
         << balls
         << endl;

    cout << "Striker : "
         << Striker->playerName
         << endl;

    cout << "Non-Striker : "
         << nonStriker->playerName
         << endl;
}



void MatchSimulation::displayResult()
{
    cout << "\n\n";
    cout << "========================================" << endl;
    cout << "             MATCH RESULT" << endl;
    cout << "========================================" << endl;


    cout << "\n"
         << firstBattingTeam->TeamName
         << " : "
         << firstInningsRuns
         << "/"
         << firstInningsWickets
         << endl;


    cout << "----------------------------------------" << endl;

    cout << secondBattingTeam->TeamName
         << " : "
         << secondInningsRuns
         << "/"
         << secondInningsWickets
         << endl;


    cout << "========================================" << endl;
    if(secondInningsRuns >= target)
    {
        int wicketsRemaining =
            10 - secondInningsWickets;

        cout << "\nWINNER : "
             << secondBattingTeam->TeamName
             << endl;

        cout << secondBattingTeam->TeamName
             << " won by "
             << wicketsRemaining
             << " wickets."
             << endl;
    }

    else
    {
        int runsDifference =
            firstInningsRuns - secondInningsRuns;

        cout << "\nWINNER : "
             << firstBattingTeam->TeamName
             << endl;

        cout << firstBattingTeam->TeamName
             << " won by "
             << runsDifference
             << " runs."
             << endl;
    }


    cout << "\n========================================" << endl;
}