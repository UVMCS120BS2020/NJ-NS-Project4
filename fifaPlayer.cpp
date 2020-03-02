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

string FifaPlayer::getName(){
    return fName;
}

void FifaPlayer::setRating(double pRating){
    fRating = pRating;
}

double FifaPlayer::getRating(){
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

std::ostream& operator << (std::ostream& outs, const FifaPlayer &p);
