//
// Created by barca on 3/2/2020.
//

#include "fifaPlayer.h"
#include <string>
using namespace std;

FifaPlayer::FifaPlayer(string pName, double pRating){
    fName = pName;
    fRating = pRating;
}

void FifaPlayer::setName(string pName){
    fName = pName;
}

string FifaPlayer::getName() const{
    return fName;
}

void FifaPlayer::setRating(double pRating){
    fRating = pRating;
}

double FifaPlayer::getRating() const{
    return fRating;
}

void FifaPlayer::addManOfMatch(){
    fName += "*";
    if(fRating <= 70)
        fRating += 5;
    else if(fRating > 70 && fRating <= 80)
        fRating += 4;
    else if(fRating > 80 && fRating <= 90)
        fRating += 3;
    else if(fRating > 90 && fRating <= 95)
        fRating += 2;
    else
        fRating += 0;
}

ostream& operator << (std::ostream& outs, const FifaPlayer &p){
    outs << "NAME: " << p.getName() << "  RATING: " << p.getRating();
    return outs;
}

bool operator < (FifaPlayer &lhs, FifaPlayer &rhs){
    return (lhs.getRating() < rhs.getRating());
}

bool operator > (FifaPlayer &lhs, FifaPlayer &rhs){
    return (lhs.getRating() > rhs.getRating());
}
