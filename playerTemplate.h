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
#include <chrono>

template<typename T>
class PlayerTemplate{
private:
    std::vector<T> fVec;
public:

    PlayerTemplate()= default;

    // finds the name of the player in the fVec and returns the index it is at.
    int find(std::string pName){
        for(int i = 0; i < fVec.size(); ++i){
            if(fVec[i].getName() == pName){
                return i;
            }
        }
        return -1;
    }

    // Sorts fVec by rating
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

    // uses chrono time in different metrics to create a 'random' number then swaps with a 'random' index
    void randomizeNS(){
        auto moment = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        int tempIndex;
        int swapIndex;
        auto moment2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        for(auto i : fVec){
            moment *= std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
            moment2 *= std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
            tempIndex = moment % (fVec.size()-1);
            swapIndex = moment2 % (fVec.size()-1);
            T temp = fVec[tempIndex];
            fVec[tempIndex] = fVec[swapIndex];
            fVec[swapIndex] = temp;
        }
    }

    // uses srand to create a sudo random number then swaps with a sudo random index
    void randomizeNJ(){
        time_t currentTime;
        srand(time(0));
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

    // takes a vector of template and sets fVec to the given vector
    void setVector(std::vector<T> pVec){
        fVec = pVec;
    }

    // returns fVec
    std::vector<T> getVector(){
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
