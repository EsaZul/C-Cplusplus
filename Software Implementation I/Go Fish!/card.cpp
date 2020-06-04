//card.cpp
#include "card.h"

using namespace std;


Card::Card(){                           // default, ace of spades
    mySuit = spades;
    myRank = 1;
}

Card::Card(int rank, Suit s){
    mySuit = s;
    myRank = rank;
    /*  1 = A;
     *  11 = J;
     *  12 = Q;
     *  13 = K;
     */

}

string Card::toString()const{           // return string version e.g. Ac 4h Js
    string returnString= "00";
    string returnString1= "F";
    switch(mySuit){
        case spades:
            returnString1 = "s";
            break;
        case clubs:
            returnString1 = "c";
            break;
        case hearts:
            returnString1 = "h";
            break;
        case diamonds:
            returnString1 = "d";
            break;
        default:
            returnString1 = "F";
    }
    switch(myRank){
        case 1:
            returnString = "A";
            break;
        case 2:
            returnString = "2";
            break;
        case 3:
            returnString = "3";
            break;
        case 4:
            returnString = "4";
            break;
        case 5:
            returnString = "5";
            break;
        case 6:
            returnString = "6";
            break;
        case 7:
            returnString = "7";
            break;
        case 8:
            returnString = "8";
            break;
        case 9:
            returnString = "9";
            break;
        case 10:
            returnString = "10";
            break;
        case 11:
            returnString = "J";
            break;
        case 12:
            returnString = "Q";
            break;
        case 13:
            returnString = "K";
            break;
        default:
            returnString = "00";
    }
    return(returnString + returnString1);

}



bool Card::sameSuitAs(const Card& c) const{ // true if suit same as c
    if(mySuit == c.mySuit){
        return(true);
    }
    else{
        return(false);
    }

}
int Card::getRank()const{                  // return rank, 1..13
    return(myRank);
}

string Card::suitString(Suit s)const{       // return "s", "h",...
    return("s");
}


string Card::rankString(int r)const{        // return "A", "2", ..."Q"
    string c;

    if(r == 1){
        c = "A";
    }
    if(r == 11){
        c = "J";
    }
    if(r == 12){
        c = "Q";
    }
    if(r == 13){
        c = "K";
    }
    if((r>1)&&(r<11)){
        c = r + '0';

    }
    if(r == 10){
        c = "10";
    }

    return(c);
}


bool Card::operator == (const Card& rhs) const{
    if(mySuit == rhs.mySuit)
        if(myRank == rhs.myRank){
            return(true);
        }
        else{
            return(false);
        }
    else{
        return(false);
    }
}


bool Card::operator != (const Card& rhs) const{
    if(mySuit == rhs.mySuit){
        if(myRank == rhs.myRank){
        return(false);
        }
        else{
            return(true);
        }
    }
    else{
        return(true);
    }
}

void Card::setSuit(Suit s){
    mySuit = s;
}

void Card::setRank(int r){
    myRank = r;
}

Card::Suit Card::getSuit(){
    return(mySuit);
}
//
Card::Card(const Card &c){
    mySuit = c.mySuit;
    myRank = c.myRank;
}