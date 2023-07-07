//Ria Mukherji
//Lab 4
//Ken Howard

#ifndef PROGRAM6_TEAM_H
#define PROGRAM6_TEAM_H
#include <string>
#include <vector>
#include "Play.h"
using namespace std;

class Team {
//Team private and public member definitions

public:
    Team(string);
    //use inline functions for getter and setter logic
    string getName(){return name;}
    void setName(string name){this->name = name;}
    int getScore(){return score;}
   void setScore(int score){this->score = score;}
   void takeTurn();
   void replay();
private:
    string name;
    int score;
    vector<Play*> plays;

};

#endif //PROGRAM4_SPRING2023_TEAM_H
