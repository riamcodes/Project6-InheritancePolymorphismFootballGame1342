//
// Created by riamu on 4/22/2023.
//
#include "Play.h"
RunPlay :: RunPlay(){
    srand(time(NULL));
    *yardsMoved = 0;
}


void RunPlay :: start(){
    vector <int> possibleRunValues = {-5,-3,-1,1,2,4,5,6,8,9};
    int randRunVal = possibleRunValues.at(rand() % 10);
    setYardsMoved(randRunVal);
}
void RunPlay :: Print(){

    cout <<"Run play for " <<  *yardsMoved << " yards" << endl;
}

//rule of 3 inline declaration in Play.cpp

