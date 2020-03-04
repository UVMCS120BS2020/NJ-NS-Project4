//
// Created by Noah Stracqualursi on 3/2/20.
//

#ifndef NJ_NS_PROJECT4_PLAYERTEMPLATE_H
#define NJ_NS_PROJECT4_PLAYERTEMPLATE_H

#include <vector>
#include <iostream>
#include <string>

template<typename T>
class PlayerTemplate{
private:
    std::vector<T> fVec;
public:

    PlayerTemplate();

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
        T temp;
        for(int i = 0; i < lastIndex ; i++){
            if (fVec[i] > fVec[i+1]){
                temp = fVec[i];
                fVec[i] = fVec[i+1];
                fVec[i+1] = temp;
            }
            --lastIndex;
        }
    }

    void randomizeNS();
    void randomizeNJ();

    void setVector(std::vector<T> pVec); //noah
    std::vector<T> getVector(); //noah

    friend std::ostream& operator << (std::ostream& outs, std::vector<T> &pVec){ //nolan
        for(auto i : pVec){
            outs << pVec[i] << "\n";
        }
        return outs;
    }
};

#endif //NJ_NS_PROJECT4_PLAYERTEMPLATE_H
