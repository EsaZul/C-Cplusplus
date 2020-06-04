//go_fish.cpp
// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides myfile and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "deck.h"
#include "player.h"
#include <fstream>
using namespace std;

//===========================================seed
// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int totalbooks(const Player Players[], const int numplayers){
    int total = 0;
    for(int i =0; i < numplayers; i++){
        total = total + Players[i].getBookSize();
    }
    return (total);
}


int main( )
{
    ofstream  myfile;
    myfile.open("gofish_results.txt");


    Deck testdeck;
    testdeck.shuffle();

    int numplayers = 2;
    Player Players[numplayers];
    int numCards = 7;

    Player Josh("Josh");
    Player Billy("Billy");
    //Player Pop("Pop");

    Players[0] = Josh;
    Players[1] = Billy;
    //Players[2] = Pop;

    int turn = rand()%numplayers;

    //deal all hands
    for(int i = 0; i < numplayers; i++){
        dealHand(testdeck, Players[i], numCards);
        myfile<<Players[i].getName()<<"'s hand:\n"<<Players[i].showHand()<<"\n";
    }
    //checks initial hands for pairs
    for(int i = 0;i < numplayers; i++){
        Card u;
        Card p;
        myfile<<Players[i].getName()<<"\n";
        if(Players[i].checkHandForBook(u, p)){
            myfile<<"start pair\n";
            myfile<<u.toString()<<"\n";
            myfile<<p.toString()<<"\n";
            u = Players[i].removeCardFromHand(u);
            p = Players[i].removeCardFromHand(p);
            Players[i].bookCards(u, p);
            myfile<< Players[i].getName()<<"'s books\n"<<Players[i].showBooks()<<"\n";
            myfile<<Players[i].getName()<<"'s new hand:\n"<<Players[i].showHand()<<"\n";
        }
    }









    //Game Logic
    while(totalbooks(Players, numplayers) != 52){   //when all cards are booked end game
        myfile<<Players[turn].getName()<<"'s turn\n";
        Card currentCard = Players[turn].chooseCardFromHand();
        myfile<<Players[turn].getName()<<" picks: "<< currentCard.toString()<<"\n";
        int askrecipient = rand()%numplayers;
        //================================================================================
        if(Players[askrecipient].getHandSize() == 0){
            askrecipient++;
            askrecipient = askrecipient%numplayers;
        }
        //================================================================================
        if(askrecipient == turn){
            askrecipient++;
            askrecipient = askrecipient%numplayers;

        }
        myfile<<Players[turn].getName()<<": ";
        if(currentCard.getRank() != 1) {
            myfile << Players[askrecipient].getName() << " do you have a " << currentCard.rankString(currentCard.getRank())<<"\n";
        }
        if(currentCard.getRank() == 1){
            myfile << Players[askrecipient].getName() << " do you have an " << currentCard.rankString(currentCard.getRank())<<"\n";
        }
        if(Players[askrecipient].cardInHand(currentCard)){
            myfile<<Players[askrecipient].getName()<<": Yes\n";
            Card pair = Players[askrecipient].removeCardFromHand(currentCard);
            Card trash = Players[turn].removeCardFromHand(currentCard);
            Players[turn].bookCards(currentCard, pair);
            if((Players[turn].getHandSize() == 0) && (testdeck.size() != 0)){
                Card drawn = testdeck.dealCard();
                if(drawn.getRank() != 42) {
                    Players[turn].addCard(drawn);
                }
            }
            if((Players[turn].getHandSize() == 0) && (testdeck.size() == 0)){
                turn++;
                turn = turn % numplayers;
            }
            if((Players[askrecipient].getHandSize() == 0) && (testdeck.size() != 0)){
                Card drawn = testdeck.dealCard();
                if(drawn.getRank() != 42) {
                    Players[askrecipient].addCard(drawn);
                }
            }
            myfile<<Players[turn].getName()<<"'s books:\n"<< Players[turn].showBooks()<<"\n";
            myfile<<Players[turn].getName()<<"'s new hand:"<<Players[turn].showHand()<<"\n";
            myfile<<Players[askrecipient].getName()<<"'s new hand: "<< Players[askrecipient].showHand()<<"\n";
        }

        else if(!Players[askrecipient].cardInHand(currentCard)){
            myfile<<Players[askrecipient].getName()<<": "<<"No, Go Fish\n";
            Card drawn1 = testdeck.dealCard();
            if(drawn1.getRank() != 42) {
                Players[turn].addCard(drawn1);
            }
            myfile<<Players[turn].getName()<<"'s new hand:\n"<<Players[turn].showHand()<<"\n";
            Card pair1;
            Card pair2;
            myfile<<Players[turn].getName()<<"'s hand\n"<<Players[turn].showHand()<<"\n";
            if(Players[turn].checkHandForBook(pair1, pair2)){
                Card trash_1 = Players[turn].removeCardFromHand(pair1);
                Card trash_2 = Players[turn].removeCardFromHand(pair2);
                Players[turn].bookCards(pair1, pair2);
                myfile<<Players[turn].getName()<<": Lucky Me!\n";
                myfile<<Players[turn].getName()<<"'s books\n"<< Players[turn].showBooks()<<"\n";
                myfile<< Players[turn].getName()<<"'s hand:\n"<< Players[turn].showHand()<<"\n";
                if((Players[turn].getHandSize() == 0)&&(testdeck.size()!= 0)){
                    myfile<<Players[turn].getName()<<"Hand is empty!\n";
                    drawn1 = testdeck.dealCard();
                    if(drawn1.getRank() != 42) {
                        Players[turn].addCard(drawn1);
                    }
                    myfile<< Players[turn].getName()<<"'s hand:\n"<< Players[turn].showHand()<<"\n";

                }

            }
            turn++;
            turn = turn%numplayers;
            if(Players[turn].getHandSize()== 0 && testdeck.size() == 0){
                turn++;
                turn = turn%numplayers;
            }
        }
    }





    myfile<<"Game Over\n";

    //Decide Winner and Prints Books
    for(int j; j < numplayers; j++){
        myfile<<Players[j].getName()<<"'s books:\n"<<Players[j].showBooks()<<"\n";
    }
    int condition = 0; // 1 if tie
    int i = 0;
    Player winner = Players[i];
    Player winner2;
    while(i < numplayers){
        if(winner.getBookSize() < Players[i].getBookSize()){
            winner = Players[i];
            condition = 0;
        }
        if(winner.getBookSize() == Players[i].getBookSize()){
            if(winner.getName() != Players[i].getName()){
                winner2 = Players[i];
                condition = 1;
            }
        }
        i++;
    }
    if(condition == 1){
        myfile<<"It's a tie\n";
        myfile<<winner.getName()<<" and "<< winner2.getName()<<" both win with "<<(winner.getBookSize())/2<<" books"<<"!\n";
        //myfile<<winner.getName()<<"'s books:\n"<<winner.showBooks()<<"\n";
        //myfile<<winner2.getName()<<"'s books:\n"<<winner2.showBooks()<<"\n";
    }
    else{
        myfile<<"The winner is "<<winner.getName()<<" with "<<(winner.getBookSize())/2<<" books"<<"!\n";
        //myfile<<winner.getName()<<"'s books:\n"<<winner.showBooks()<<"\n";
    }

    for(int i = 0; i<numplayers;i++){
        myfile<<Players[i].getName()<<"'s Books:\n"<<Players[i].showBooks()<<"\n";
    }

    myfile.close();

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



