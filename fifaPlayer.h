//
// Created by barca on 3/2/2020.
//

#ifndef NJ_NS_PROJECT4_FIFAPLAYER_H
#define NJ_NS_PROJECT4_FIFAPLAYER_H

#include <string>

class FifaPlayer{
private:
    std::string fName;
    double fRating;

public:
    FifaPlayer(std::string pName, double pRating);

    void setName(std::string pName);

    std::string getName();

    void setRating(double pRating);

    double getRating();

    void addManOfMatch();

    friend std::ostream& operator << (std::ostream& outs, const FifaPlayer &p);
};

#endif //NJ_NS_PROJECT4_FIFAPLAYER_H
