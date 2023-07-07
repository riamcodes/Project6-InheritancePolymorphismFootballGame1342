//Ria Mukherji
//Lab 4
//Ken Howard
#ifndef PROGRAM6_SCRIMMAGE_H
#define PROGRAM6_SCRIMMAGE_H
#include "Team.h"

class Scrimmage {
public:
    Scrimmage();
    void play();
    void printScoreboard();
    void printReplay();
private:
    vector<Team> teams;
//Scrimmage class definition with private and public member definitions

};
#endif //PROGRAM4_SPRING2023_SCRIMMAGE_H
