#ifndef PLAYINGXI_H
#define PLAYINGXI_H

#include "PlayerManagement.h"

struct PlayingNode
{
    Player *player;
    PlayingNode *next;
};

class PlayingXI
{
    private : 
        PlayingNode *head ;
        PlayingNode *tail ;
        int count ;
    public:
        PlayingXI();
        void addPlayer(Player *player);
        int size();
        void display();    
};

#endif
