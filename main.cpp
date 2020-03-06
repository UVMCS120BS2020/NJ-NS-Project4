//
// Created by barca on 3/4/2020.
//

#include "fifaPlayer.h"
#include "playerTemplate.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define NUM_TRIALS 100;

int testRandomnessNolan(PlayerTemplate<FifaPlayer> &templateObject);
int testRandomnessNoah(PlayerTemplate<FifaPlayer> &templateObject);

int main() {

    vector<FifaPlayer> playerVec;
    PlayerTemplate<FifaPlayer> myThing;

    for(int i = 0; i < 50; ++i){
        stringstream ss;
        ss << "p";
        ss << i;
        playerVec.push_back(FifaPlayer(ss.str(), i));
    }
    myThing.setVector(playerVec);

    cout << "The find function found player 'p10' at index: " << myThing.find("p10") << endl;

    //Testing the output operator and sort function
    cout << "Original Creation of Vector" << endl;
    cout << myThing << endl;
    cout << "\n" << endl;

    myThing.sort();
    cout << "Vector after sorting function is called" << endl;
    cout << myThing << endl;
    cout << "\n" << endl;
    //Testing the randomness metric
    int rInt = testRandomnessNolan(myThing);
    cout << rInt << endl;
    double rRatio = double(rInt)/(5000); //There are 50 indices in each vector, 100 vectors per trial, so there are 5000 possible equal vectors
    cout << "The randomness metric ratio is: " << rRatio << endl;
    cout << "This means that %" << rRatio*100 << " of trials were identical after put through Nolan's randomizer" << endl;

    rInt = testRandomnessNoah(myThing);
    cout << rInt << endl;
    rRatio = double(rInt)/(5000); //There are 50 indices in each vector, 100 vectors per trial, so there are 5000 possible equal vectors
    cout << "The randomness metric ratio is: " << rRatio << endl;
    cout << "This means that " << rRatio*100 << "% of trials were identical after put through Noah's randomizer" << endl;

    return 0;

}

int testRandomnessNolan (PlayerTemplate<FifaPlayer> &templateObject){
    vector<vector<FifaPlayer>> vecOfVecs;

    for(int i = 0; i < NUM_TRIALS ++i){
        templateObject.randomizeNJ();
        vecOfVecs.push_back(templateObject.getVector());
    }

    int equalInstances = 0;

    for(int k = 0; k < vecOfVecs.size()-1; ++k){
        for(int j = k; j < vecOfVecs.size()-1; ++j){
            if(k!=j)
                if(vecOfVecs[k] == vecOfVecs[j])
                    ++ equalInstances;
        }
    }
    return equalInstances;
}

int testRandomnessNoah (PlayerTemplate<FifaPlayer> &templateObject){
    vector<vector<FifaPlayer>> vecOfVecs;

    for(int i = 0; i < NUM_TRIALS ++i){
        templateObject.randomizeNS();
        vecOfVecs.push_back(templateObject.getVector());
    }

    int equalInstances = 0;

    for(int k = 0; k < vecOfVecs.size()-1; ++k){
        for(int j = k; j < vecOfVecs.size()-1; ++j){
            if(k!=j)
                if(vecOfVecs[k] == vecOfVecs[j])
                    ++ equalInstances;
        }
    }
    return equalInstances;
}

bool operator == (const FifaPlayer &lhs, const FifaPlayer &rhs) {
    return lhs.getName() == rhs.getName() && lhs.getRating() == rhs.getRating();
}
