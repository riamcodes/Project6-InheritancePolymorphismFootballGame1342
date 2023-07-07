//Ria Mukherji
//Lab 4
//Ken Howard
#include "Play.h"


Play::Play() {
    //constructor:
    //Seed random
    //initialize yardsMoved to 0
    srand(time(NULL));
    *yardsMoved = 0;
  }

//these methods will be overridden by the subclasses
void Play::start() {}

void Play::Print() { }

//this method is specific to be overridden by KickPlay specifically
//I couldn't get it to be a specific method to KickPlay without it causing an error so its here
int Play ::getKickPlayValue() {}
//rule of 3

//destructor
Play :: ~Play(){delete yardsMoved;}
//copy constructor
Play :: Play(const Play &copy){yardsMoved = new int(*copy.yardsMoved);}


//copy assignment operator
Play &Play::operator=(const Play &copy) {
    if (this != &copy) {
       delete yardsMoved;
         yardsMoved = new int;
        *yardsMoved = *(copy.yardsMoved);
    }
    return *this;
}