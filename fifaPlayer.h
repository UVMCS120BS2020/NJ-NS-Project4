//
// Created by barca on 3/2/2020.
//

#ifndef NJ_NS_PROJECT4_FIFAPLAYER_H
#define NJ_NS_PROJECT4_FIFAPLAYER_H

#include <string>
#include <iostream>

class FifaPlayer{
private:
    std::string fName;
    double fRating;

public:
    FifaPlayer(std::string pName, double pRating);

    void setName(std::string pName);

    std::string getName() const;

    void setRating(double pRating);

    double getRating() const;

    void addManOfMatch();

    friend bool operator < (FifaPlayer &lhs, FifaPlayer &rhs);

    friend bool operator > (FifaPlayer &lhs, FifaPlayer &rhs);

    friend std::ostream& operator << (std::ostream& outs, const FifaPlayer &p);
};

#endif //NJ_NS_PROJECT4_FIFAPLAYER_H
