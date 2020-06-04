//player.cpp
#include "player.h"
#include "card.h"
#include "deck.h"
#include <cstdlib>

using namespace std;


Player::Player(){
    myHand;
    myBook;

    myName = "NAME";
}

Player::Player(string _name) {
    myHand;
    myBook;
    myName = _name;
}


string Player::getName() const {
    return myName;
}

void Player::addCard(Card c){       //adds a card to the hand
    myHand.push_back(c);

}



void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}



//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){
    int i = 0;
    int j = i+1;
    while(i < (this->getHandSize()-1)) {
        while (j < this->getHandSize()) {
            if (this->myHand[i].getRank() == this->myHand[j].getRank()) {
                if(this->myHand[i] != this->myHand[j]) {
                    c1 = this->myHand[i];
                    c2 = this->myHand[j];
                    return true;
                }
            }
        j++;
        }
        i++;
        j = i+1;
    }
    return(false);
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//bool rankInHand(Card c) const;

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
    int random = rand()%this->myHand.size();

    return(myHand[random]);


}




//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    int i = 0;
    while(i<myHand.size()){
        if(myHand[i].getRank() == c.getRank()){
            return(true);
        }
        i++;
    }
    return(false);

}



//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    int i = 0;
    while(myHand[i].getRank()!= c.getRank()){
        i++;
    }
    Card hold = myHand[i];
    myHand.erase(myHand.begin()+i);

    return(hold);
}

string Player::showHand() const{
    int i = 0;
    string returnString;
    while(i<myHand.size()){
        //cout<<myHand[i].toString()<<"\n";
        returnString = returnString + myHand[i].toString();
        i++;
    }
    return(returnString);

}


string Player::showBooks() const{
    int i = 0;
    string returnString;
    while(i<myBook.size()){
        //cout<<myBook[i].toString()<<"\n";
        returnString = returnString + myBook[i].toString();
        i++;
    }
    return(returnString);
}

int Player::getHandSize() const{
    return(myHand.size());


}



int Player::getBookSize() const{
    return(myBook.size());
}




//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//bool checkHandForPair(Card &c1, Card &c2);

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

//bool Player::sameRankInHand(Card c) const;


Player& Player::operator =(const Player &p){
    myHand = p.myHand;
    myBook = p.myBook;
    myName = p.myName;
    return (*this);
}