//Ria Mukherji
//Lab 4
//Ken Howard
#include "Team.h"

//Team constructor:
// initialize name to string passed in
Team::Team(string teamName) {
    setName(teamName);
    score = 0;
}

//called at end of game optionally to replay a summary of all Plays
void Team::replay() {
    for(int i = 0; i < plays.size(); i++){
        plays.at(i)->Print();
    }
}

//game logic for turns in the game described in function
void Team::takeTurn() {
    int location = 20;
    int downCounter = 1;
    int target = location + 10;
    while(true) {
        // cout << setfill(' ') << setw(2) << right <<  The spacing didn't work ask about in class
        cout << "  Ball at: " << location << ".     Down #" << downCounter << endl;
        //create new play and add to vector
        //add kick option for location is greater than 70
        if (location >= 70) {


            cout << "  Run, Pass, or Kick (R/P/K)?";
            char choice;
            cin >> choice;

            //if the user chooses R add RunPlay to the vector
            if ((choice == 'R') || (choice == 'r')) {
                plays.push_back(new RunPlay);
            }
                //if the user chooses P add PassPlay to the vector
            else if ((choice == 'P') || (choice == 'p')) {
                plays.push_back(new PassPlay);
            } else if ((choice == 'K') || (choice == 'k')) {
              //  cout << "KICK PLAY INVOKED TEST TEST TEST";
                plays.push_back(new KickPlay);
                Play *lastKickPlay = plays.back();
                plays.pop_back();
                lastKickPlay ->start();
                int didKickWork = lastKickPlay-> getKickPlayValue();
                if (didKickWork == 0){
                    cout << "Kick no good." << endl;
                    cout << "Turn over" << endl;
                    plays.push_back(lastKickPlay);
                   break;
                }
                else if (didKickWork == 1){
                    cout << "Kick good for 3 points!" << endl;
                    score += 3;
                    cout << "Turn over" << endl;
                    plays.push_back(lastKickPlay);
                   break;
                }
            }

            //after the type of play is chosen and added get the last element of the vector
            Play *lastPlay = plays.back();
            //pop it off the back of the vector while we are editing its contents so its not duplicated
            plays.pop_back();

            //edit and invoke methods on the last play
            lastPlay->start();
            //When the Play has finished its start method, get its yardsMoved value
            int yardsMoved = lastPlay-> getYardsMoved();
            lastPlay->setYardsMoved(yardsMoved);
            plays.push_back(lastPlay);
            //target to move 10 yards

            //add yardsMoved to the location
            location += yardsMoved;
            // Print "Moved n yards", "Moved back n yards" or "no yards" depending on what happens
            if (yardsMoved == 0) {
                cout << "  No yards" << endl;
            } else if (yardsMoved > 0) {
                cout << "  Moved " << yardsMoved << " yards" << endl;
            } else if (yardsMoved < 0) {
                cout << "  Moved back " << (-1 * yardsMoved) << " yards" << endl;
            }

            //If location >= 100, declare touchdown and add 6 points to the team's score
            if (location >= 100) {
                cout << "  Touchdown! " << endl;
                score += 6;
                break;
            }
                //Otherwise, if location < target, increment down counter. If down counter > 4, end the turn
                // If location >= target, set target = location + 10
            else if (location < target) {
                downCounter++;
                if (downCounter > 4) {
                    cout << "  Turn over" << endl;
                    break;
                }
            } else if (location >= target) {
                target = location + 10;
                downCounter = 1;
            }
            cout << "  " << (target - location) << " yards to 1st down" << endl;
        }
        else {

            cout << "  Run or Pass(R/P)?";
            char choice;
            cin >> choice;

            //if the user chooses R add RunPlay to the vector
            if ((choice == 'R') || (choice == 'r')) {
                plays.push_back(new RunPlay);
            }
                //if the user chooses P add PassPlay to the vector
            else if ((choice == 'P') || (choice == 'p')) {
                plays.push_back(new PassPlay);
            }

            //after the type of play is chosen and added get the last element of the vector
            Play *lastPlay = plays.back();
            //pop it off the back of the vector while we are editing its contents so its not duplicated
            plays.pop_back();

            //edit and invoke methods on the last play
            lastPlay->start();
            //When the Play has finished its start method, get its yardsMoved value
            int yardsMoved = lastPlay->getYardsMoved();
            lastPlay->setYardsMoved(yardsMoved);
            plays.push_back(lastPlay); //CHANGED CHANGED CHANGED
            //target to move 10 yards

            //add yardsMoved to the location
            location += yardsMoved;
            // Print "Moved n yards", "Moved back n yards" or "no yards" depending on what happens
            if (yardsMoved == 0) {
                cout << "  No yards" << endl;
            } else if (yardsMoved > 0) {
                cout << "  Moved " << yardsMoved << " yards" << endl;
            } else if (yardsMoved < 0) {
                cout << "  Moved back " << (-1 * yardsMoved) << " yards" << endl;
            }

            //If location >= 100, declare touchdown and add 6 points to the team's score
            if (location >= 100) {
                cout << "  Touchdown! " << endl;
                score += 6;
                break;
            }
                //Otherwise, if location < target, increment down counter. If down counter > 4, end the turn
                // If location >= target, set target = location + 10
            else if (location < target) {
                downCounter++;
                if (downCounter > 4) {
                    cout << "  Turn over" << endl;
                    break;
                }
            } else if (location >= target) {
                target = location + 10;
                downCounter = 1;
            }
            cout << "  " << (target - location) << " yards to 1st down" << endl;
        }

    }
}

