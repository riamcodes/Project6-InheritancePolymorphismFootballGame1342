//
// Created by riamu on 4/23/2023.
//
#include "Play.h"
//RunPlay :: RunPlay();


KickPlay::KickPlay() {
    srand(time(NULL));
    *yardsMoved = 0;
}


void KickPlay :: start(){
    vector <int> possibleKickValues = {0,1};
    *kickPlayValue = possibleKickValues.at(rand() % 2);
}

int KickPlay :: getKickPlayValue(){
    return *kickPlayValue;
}

void KickPlay :: Print(){
string value;
if (this-> getKickPlayValue() == 0){
    value = "was not successful";
}
else if(this->getKickPlayValue() == 1){
    value = "was successful";
}
    cout <<"Kick play " << value << endl;// <<  yardsMoved << " yards" << endl;
}

//rule of 3 inline declaration in Play.cpp