//
// Created by Noah Stracqualursi on 3/2/20.
//

#ifndef NJ_NS_PROJECT4_PLAYERTEMPLATE_H
#define NJ_NS_PROJECT4_PLAYERTEMPLATE_H

#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <random>

template<typename T>
class PlayerTemplate{
private:
    std::vector<T> fVec;
public:

    PlayerTemplate()= default;

    int find(std::string pName){
        for(int i = 0; i < fVec.size(); ++i){
            if(fVec[i].getName() == pName){
                return i;
            }
        }
        return -1;
    }

    //nolan
    void sort(){
        int lastIndex = fVec.size() - 1;
        for(int k = 0; k < lastIndex-1; k++) {
            for (int i = 0; i < lastIndex; i++) {
                if (fVec[i] < fVec[i + 1]) {
                    T temp = fVec[i];
                    fVec[i] = fVec[i + 1];
                    fVec[i + 1] = temp;
                }
            }
        }
    }

    void randomizeNS();

    void randomizeNJ(){
        time_t currentTime;
        int tempIndex;
        int swapIndex;
        for(auto i : fVec){
            tempIndex = rand() % (fVec.size()-1);
            swapIndex = rand() % (fVec.size()-1);
            T temp = fVec[tempIndex];
            fVec[tempIndex] = fVec[swapIndex];
            fVec[swapIndex] = temp;
        }
    }

    void setVector(std::vector<T> pVec){ //nolan
        fVec = pVec;
    }

    std::vector<T> getVector(){ //nolan
        return fVec;
    }

    friend std::ostream& operator << (std::ostream& outs, PlayerTemplate<T> playerTemplate){ //nolan
        std::vector<T> templateVec = playerTemplate.getVector();
        for(auto i : templateVec)
            outs << "NAME: " << i.getName() << "  RATING: " << i.getRating() << "\n";
        return outs;
    }
};

#endif //NJ_NS_PROJECT4_PLAYERTEMPLATE_H
