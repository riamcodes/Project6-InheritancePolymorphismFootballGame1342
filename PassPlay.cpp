#include "Play.h"


PassPlay ::PassPlay() {
    srand(time(NULL));
    *yardsMoved = 0;
}

void PassPlay :: start(){
   // cout << "PASSPLAY STARTED TEST TEST TEST" << endl;
    vector <int> possiblePassValues = {-10,-5,0,0,5,10,15,20,25,30};
    int randPassVal = possiblePassValues.at(rand() % 10);
    setYardsMoved(randPassVal);
}
void PassPlay :: Print(){
    cout <<"Pass play for " <<  *yardsMoved  << " yards" << endl;//used to be *getYardsMoved
}

//rule of 3

//destructor
PassPlay :: ~PassPlay(){
    delete yardsMoved;
}
//copy constructor
PassPlay :: PassPlay(const PassPlay &copy) {
    if (this != &copy) {
        delete yardsMoved;
        yardsMoved = new int;
        *yardsMoved = *(copy.yardsMoved);
    }
//copy assignment operator
//copy assignment operator declared inline because it wouldn't accept it here for some reason
//see Play.h file
}