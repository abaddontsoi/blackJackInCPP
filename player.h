#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

class player
{
private:
    vector<card> hand;
public:
    player();
    void addCard(card newCard);
    vector<card> getHand();
    ~player();
};

void player::addCard(card newCard){
    hand.push_back(newCard);
}

vector<card> player::getHand(){
    return this->hand;
}

player::player()
{
}

player::~player()
{
}