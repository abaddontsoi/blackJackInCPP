// class of cards

#include <iostream>

using namespace std;

class card
{
private:
    int point;
    char *suit;
    bool inPlayerHand;
public:
    card(int p=0, char *suit = "", bool inPlayerHand=false):point(p), suit(suit), inPlayerHand(inPlayerHand) {};
    void setPoint(int p = 0);
    int getPoint();
    void setSuit(char* suit);
    char *getSuit();
    void setInHand(bool v);
    bool getInHand();


    friend ostream& operator<< (ostream& out, card rhs);
    ~card();
};

void card::setInHand(bool v){
    this->inPlayerHand = v;
}
bool card::getInHand(){
    return inPlayerHand;
}


void card::setPoint(int p){
    this->point = p;
}

int card::getPoint(){
    return this->point;
}

void card::setSuit(char* suit){
    this->suit = suit;
}
char* card::getSuit(){
    return this->suit;
}

ostream& operator<< (ostream& out, card rhs){
    out <<rhs.getSuit() << rhs.getPoint()<<'\n';
    return out;
}

card::~card()
{
}
