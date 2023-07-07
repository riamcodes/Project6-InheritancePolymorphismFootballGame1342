#include "Scrimmage.h"
#include <iostream>
using namespace std;



int main() {
    Scrimmage * s = new Scrimmage();
    s->play();
    char ans;
    cout << "Print game replay (Y/N)?";
    cin >> ans;
    if (toupper(ans) == 'Y')
        s->printReplay();
    return 0;
}
