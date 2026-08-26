#include <iostream>
#include "PlayingXI.h"
using namespace std;
PlayingXI::PlayingXI()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}
void PlayingXI::addPlayer(Player *player)
{
    PlayingNode *newNode = new PlayingNode;
    newNode->player = player;
    newNode->next = nullptr;
    if(head == nullptr)
    {
        head = tail = newNode;
        count ++;
        return;

    }
    tail->next = newNode;
    tail = newNode;
    count ++;
}
int PlayingXI::size()
{
    return count;
}
void PlayingXI::display()
{
    PlayingNode *temp = head;
    int position = 1;
    while(temp != nullptr)
    {
        cout << position << ". "
             << temp->player->playerName
             << " | "
             << temp->player->role
             << endl;
        temp = temp->next;
        position ++;           
    }
}