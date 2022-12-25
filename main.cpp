#include <iostream>
#include <time.h>
#include "card.h"
#include "player.h"
using namespace std;

void printDeck(card *deck){
    for(int i = 0; i < 52; i++)
        cout << *(deck+i);
}

card* createDeck(card *deck){
    card *returnDeck = deck;
    card *initPtr = deck;
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            char *temp;
            switch (j)
            {
            case 1:
                temp = "spades";
                break;
            case 2:
                temp = "hearts";
                break;
            case 3:
                temp = "diamonds";
                break;
            case 4:
                temp = "clubs";
                break;           
            default:
                break;
            }
            initPtr->setPoint(i);
            initPtr->setSuit(temp);
            initPtr->setInHand(false);
            initPtr++;
        }
    }
    return returnDeck;
}

card* shuffleDeck(card *deck){
    srand(time(NULL));
    card *shuffled = new card[52];

    // the boolean array identifies which card from deck has been copied to shuffled
    bool collected[52] = {0};
    for(int i = 0; i<52; i++){
        int randS = rand()%52;
        while (collected[randS])
        {
            randS = rand()%52;
        }
        shuffled[i] = *(deck + randS);
    }
    return shuffled;
}

int main() {
    // game environment
    int roundCounter = 0;
    card deck[52];
    card *initPtr = deck;

    // controllers
    bool ended = false;

    // create and shuffle the deck
    initPtr = createDeck(initPtr);
    initPtr = shuffleDeck(initPtr);

    // create players
    player me,p1,p2,p3,host;

    // game logic starts
    while (!ended)
    {
        // identify currnet player
        // design which player's round
        player *current;
        switch (roundCounter%5)
        {
        case 0:
            *current = host;
            break;
        
        case 1:
            *current = p1;
            break;
        
        case 2:
            *current = p2;
            break;
        
        case 3:
            *current = p3;
            break;
        
        case 4:
            *current = me;
            break;
        }
        // ended = true;
    }

    // reset the pointer after game
    initPtr = nullptr;
    return 0;
}