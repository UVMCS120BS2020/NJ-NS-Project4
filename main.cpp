//
// Created by barca on 3/4/2020.
//

#include "fifaPlayer.h"
#include "playerTemplate.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {

    FifaPlayer p1 = FifaPlayer("Lionel Messi", 94);
    FifaPlayer p2 = FifaPlayer("Christiano Ronaldo", 92);
    FifaPlayer p3 = FifaPlayer("Fred", 92);
    FifaPlayer p4 = FifaPlayer("Juan Mata", 84);
    FifaPlayer p5 = FifaPlayer("Bruno Fernandes", 89);
    FifaPlayer p6 = FifaPlayer("Christian Benteke", 73);
    FifaPlayer p7 = FifaPlayer("Serge Gnabry", 62);
    FifaPlayer p8 = FifaPlayer("Michael Bradly", 67);
    FifaPlayer p9 = FifaPlayer("Landon Donovan", 53);
    FifaPlayer p10 = FifaPlayer("Eden Hazard", 89);

    vector<FifaPlayer> playerVec{p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};

    PlayerTemplate<FifaPlayer> myThing;
    myThing.setVector(playerVec);

    cout << myThing.find("Bruno Fernandes") << endl;

    cout << myThing << endl;
    cout << "\n" << endl;
    myThing.sort();
    cout << myThing << endl;
    cout << "\n" << endl;

    myThing.randomizeNJ();
    cout << myThing << endl;

    return 0;

}
