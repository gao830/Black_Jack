#include "View.hpp"
using namespace std;

View::View() {
    
}

void View::greeting() {
    cout << "Welcome to Black Jack game!" << endl;
    cout << endl;
}

void View::promptForHoldOrHit() {
    cout << "Do you want to hold or hit? (1 for hold, 2 for hit)" << endl;
    cout << endl;
    return;
}

void View::displayWinner(int identifier) {
    if(identifier == 0) {
        cout << "It's a tie!" << endl;
        cout << endl;
    } else if (identifier == 1) {
//        cout << "
    }
}

void View::displayCardDrawnAndScore(int score, string cardDrawn) {
    cout << "Card drawn: " << cardDrawn << endl;
    cout << endl;
    cout << "Score: " << score << endl;
    cout << endl;
}

