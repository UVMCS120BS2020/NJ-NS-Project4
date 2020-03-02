//
// Created by Noah Stracqualursi on 3/2/20.
//

#ifndef NJ_NS_PROJECT4_PLAYERTEMPLATE_H
#define NJ_NS_PROJECT4_PLAYERTEMPLATE_H

#include <vector>

template<typename T>
class PlayerTemplate{
private:
    std::vector<T> fVec;
public:

    PlayerTemplate();

    int find(); //noah
    void sort(); //nolan

    void randomizeNS();
    void randomizeNJ();

    void setVector(std::vector<T> pVec); //noah
    std::vector<T> getVector(); //noah

    friend std::ostream& operator << (std::ostream& outs, std::vector<T> &pVec); //nolan
};

#endif //NJ_NS_PROJECT4_PLAYERTEMPLATE_H
