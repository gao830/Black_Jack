#include "Controller.hpp"

Controller::Controller(View &view) {
    this -> view = view;
}

void Controller::startGame() {
//    int choice;
//    model.initDeck();
    view.greeting();
//    view.promptForHoldOrHit();
//    cin >> choice;
//    while(choice != 1) {
//        if(choice == 2) {
////            cout << "hit" << endl;
//            cardDrawn = model.drawCard(1);
//            model.updateScores();
//            playerScore = model.getPlayerScore();
//            view.displayCardDrawnAndScore(playerScore, cardDrawn);
//            view.promptForHoldOrHit();
//            cin >> choice;
//        }
//        else {
//            view.promptForHoldOrHit();
//            cin >> choice;
//        }
//        
//    }
//    if (choice == 1) {
//        cout << "hold" << endl;
//    }
    model.playRound();
        
}

void Controller::hitOrHold() {
    
}
