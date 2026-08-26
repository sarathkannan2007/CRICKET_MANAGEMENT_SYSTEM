#include <iostream>
#include "BestX1.h"
#include "PlayingXI.h"
#include "PlayerManagement.h"
#include "TeamManagement.h"
using namespace std;


struct Node
{
    Player *player;
    Node *next;
};
class PriorityQueue
{
    private :
        Node *front;
        Node *rear;
        int count;
    public :
        PriorityQueue()
        {
            front = nullptr;
            rear = nullptr;
            count = 0;
        }
        int getScore(Player *player)
        {
            if(player->role == "Batsman")
            {
                return player->battingRating;
            }
            if(player->role == "Wicketkeeper")
            {
                return player->battingRating;
            }
            if(player->role == "All-rounder")
            {
                return (player->battingRating + player->bowlingRating)/2;
            }
            if(player->role == "Bowler")
            {
                return player->bowlingRating;
            }
            return 0;
        }
        void enqueue(Player *player)
        {
            Node *newNode = new Node;
            newNode->player = player;
            newNode->next = nullptr;
            int newScore = getScore(player);
            if ( front == nullptr)
            {
                front = rear = newNode;
                count ++;
                return;
            }
            if(newScore > getScore(front->player))
            {
                newNode->next = front;
                front = newNode;
                count ++;
                return;
            }
            Node *temp = front;
            while(temp->next != nullptr && getScore(temp->next->player) >= newScore)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            if(newNode->next == nullptr)
            {
                rear = newNode;
            }
            count ++;
        }
        Player *dequeue()
        {
            if(front == nullptr)
            {
                cout << "Empty Player Detail. " << endl;
                return nullptr;
            }
            Node *temp = front;

            Player *player = temp->player;

            front = front->next;

            if(front == nullptr)
            {
                rear = nullptr;
            }
            delete temp;
            count --;
            return player;
        }
        int size()
        {
            return count;
        }
        bool isEmpty()
        {
            if(front == nullptr)
            {
                return true;
            }
            return false;
        }
};

void predictBestX1(int teamID)
{

    Team *team = getTeamByID(teamID);
    if ( team == nullptr)
    {
        cout << "Invalid Team ID. " << endl;
        return;
    }
    PriorityQueue batsmanQueue;
    PriorityQueue wicketkeepermanQueue;
    PriorityQueue allRounderQueue;
    PriorityQueue bowlerQueue;

    Player *temp =  getPlayerHead();

    while(temp != nullptr)
    {
        if(temp->teamID == teamID)
        {
            if (temp->role == "Batsman")
            {
                batsmanQueue.enqueue(temp);
            }
            else if (temp->role == "Wicketkeeper")
            {
                wicketkeepermanQueue.enqueue(temp);
            }
            else if (temp->role == "All-rounder")
            {
                allRounderQueue.enqueue(temp);
            }
            else if (temp->role == "Bowler")
            {
                bowlerQueue.enqueue(temp);
            }
        }
        temp = temp->next;
    }
    cout << "BEST XI - " << team->TeamName << endl;
    cout << "Batsman Available : " << batsmanQueue.size() << endl;
    cout << "WicketKeeper Available : " << wicketkeepermanQueue.size() << endl;
    cout << "All Rounder Available : " << allRounderQueue.size() << endl;
    cout << "Bowlers Available : " << bowlerQueue.size() << endl;

    cout << "Playing XI - " << team->TeamName <<endl;
    cout << endl;

    PlayingXI playingXI;
    for(int i = 0;i<4;i++)
    {
        Player *player = batsmanQueue.dequeue();
        if(player != nullptr)
        {
            playingXI.addPlayer(player);
        }
    }
    for(int i = 0;i<2;i++)
    {
        Player *player = allRounderQueue.dequeue();
        if(player != nullptr)
        {
            playingXI.addPlayer(player);
        }
    }

    Player *player = wicketkeepermanQueue.dequeue();
        if(player != nullptr)
        {
            playingXI.addPlayer(player);
        }

    for(int i = 0;i<4;i++)
    {
        Player *player = bowlerQueue.dequeue();
        if(player != nullptr)
        {
            playingXI.addPlayer(player);
        }
    }
    playingXI.display();
    
}
