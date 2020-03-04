//
// Created by Noah Stracqualursi on 3/2/20.
//

#ifndef NJ_NS_PROJECT4_PLAYERTEMPLATE_H
#define NJ_NS_PROJECT4_PLAYERTEMPLATE_H

#include <vector>
#include <iostream>
#include <string>
#include <ctime>

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
            currentTime = time(NULL);
            tempIndex = abs(currentTime*1000) % (fVec.size()-1);
            T temp = fVec[tempIndex];
            swapIndex = abs(currentTime*1000) % (fVec.size()-1);
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

    friend std::ostream& operator << (std::ostream& outs, std::vector<T> pVec){ //nolan TODO: THIS STILL HAS TO BE FIGURED OUT
        for(auto i : pVec){
            outs << pVec[i] << "\n";
        }
        return outs;
    }
};

#endif //NJ_NS_PROJECT4_PLAYERTEMPLATE_H
