//
// Created by Ken Howard on 3/8/23.
//

#ifndef PROGRAM6_TEMPLATE_PLAY_H
#define PROGRAM6_TEMPLATE_PLAY_H
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

class Play {
public:
    Play();
    int getYardsMoved(){return *yardsMoved;} // changed
    void setYardsMoved(int yardsMoved) {*this->yardsMoved = yardsMoved;}//{this->yardsMoved = yardsMoved;} // changed
    virtual void start();
   virtual int getKickPlayValue();
    virtual void Print();

    //rule of 3 declared and written in class
    ~Play(); //Destructor
    Play(const Play&);
    Play& operator=(const Play&);//copy Constructor
   //Play class definition with private and public member definitions


protected:
   // int yardsMoved;
   int *yardsMoved = new int;
};

//add RunPlay as a kind of play
class RunPlay : public Play {
public:
    RunPlay();
    void start();
    void Print();
    //rule of 3 inline declaration
// Copy constructor
   RunPlay(const RunPlay& copy) : Play(copy) {
        yardsMoved = new int(*copy.yardsMoved);
   }

 // Copy assignment operator
    RunPlay& operator=(const RunPlay& copy) {
        if (this != &copy) {
            delete yardsMoved;
            yardsMoved = new int;
            *yardsMoved = *(copy.yardsMoved);
        }
        return *this;
    }
// Destructor
    ~RunPlay() {delete yardsMoved;}
protected:

};

//add PassPlay as a kind of play
//rule of 3 declaration and written in class
//copy assignment operator written inline because for some reason it wouldn't let me write it in the class
class PassPlay : public Play {
public:
    PassPlay();
    void start();
    void Print();
    ~PassPlay(); //Destructor
    PassPlay(const PassPlay&);//copy constructor
    //copy assignment operator inline
    PassPlay& operator=(const PassPlay& copy) {
        if (this != &copy) {
          delete yardsMoved;
            yardsMoved = new int;
            *yardsMoved = *(copy.yardsMoved);
        }
        return *this;}

protected:
};

class KickPlay : public Play {
public:
    KickPlay();

    KickPlay(const PassPlay &copy);

    void start();
    void Print();
    int getKickPlayValue();
//rule of 3 inline declaration
     // Copy constructor
    KickPlay(const KickPlay& copy) : Play(copy) {
        yardsMoved = new int(*copy.yardsMoved);
        kickPlayValue = new int (*copy.kickPlayValue);}



    // Copy assignment operator
    KickPlay& operator=(const KickPlay& copy) {
        if (this != &copy) {
            delete yardsMoved;
            yardsMoved = new int;
            *yardsMoved = *(copy.yardsMoved);

            delete kickPlayValue;
            kickPlayValue = new int;
            *kickPlayValue = *(copy.kickPlayValue);
        }
        return *this;
    }
// Destructor
    ~KickPlay() {
        delete yardsMoved;
        delete kickPlayValue;
    }

protected:
    int *kickPlayValue = new int;
};


#endif //PROGRAM4_SPRING2023_PLAY_H
