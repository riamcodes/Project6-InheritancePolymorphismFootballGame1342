//Ria Mukherji
//Lab 4
//Ken Howard
#include "Scrimmage.h"

//Call the replay function for each team at the end
void Scrimmage::printReplay() {
   cout << "Play summary for " <<  teams.at(0).getName() << ":\n";
   teams.at(0).replay();
   cout << endl;
    cout << "Play summary for " <<  teams.at(1).getName() << ":\n";
   teams.at(1).replay();
}

//Scrimmage constructor:
//Prompt for name of each team
//Create two team objects
//Add teams to the teams vector
Scrimmage::Scrimmage() {
    string team1, team2;
    cout << "Enter name for team #1:";
    cin >> team1;
    cout << "Enter name for team #2:";
    cin >> team2;

    //add to vector
    teams.push_back(team1);
    teams.push_back(team2);
}

//play to loop until game ends by 12 point victory
void Scrimmage::play() {
   // loop until game ends
   while(true) {
       //   Call takeTurn for each team
       cout << teams.at(0).getName() << "'s Turn" << endl;
       teams.at(0).takeTurn();
       printScoreboard();

       //check if winner and break
       int a = teams.at(0).getScore();
       int b = teams.at(1).getScore();
       if ((a>=12)||(b>=12)){
           break;
       }

       //next turn
       cout << teams.at(1).getName() << "'s Turn" << endl;
       teams.at(1).takeTurn();
       printScoreboard();
       cout << endl;

       //again check if winner and break
       //check if winner and break
       a = teams.at(0).getScore();
       b = teams.at(1).getScore();
       if ((a>=12)||(b>=12)){
           break;
       }
   }

   //Decide which team won and print statement
    if(teams.at(0).getScore() > teams.at(1).getScore()){
        cout << "  " << teams.at(0).getName() << " won!! Game Over" << endl;
        cout << endl;
    }
    else {
        cout << "  " << teams.at(1).getName()  << " won!! Game Over" << endl;
        cout << endl;
    }
}

// print the team name and score of each team
void Scrimmage::printScoreboard() {
 cout  << "SCOREBOARD" << endl;
 cout << teams.at(0).getScore() << "     " << teams.at(0).getName() << endl;
 cout << teams.at(1).getScore() << "     " << teams.at(1).getName() << endl;
}