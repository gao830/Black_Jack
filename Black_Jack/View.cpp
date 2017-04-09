#include "View.hpp"
using namespace std;

View::View() {
    
}

void View::promptForHoldOrHit() {
    cout << "Do you want to hold or hit? (1 for hold, 2 for hit)" << endl;
    
    return;
}

void View::displayWinner(int identifier) {
    if(identifier == 0) {
        cout << "It's a tie!" << endl;
    } else if (identifier == 1) {
//        cout << "
    }
}
