#include "Controller.hpp"

Controller::Controller(View &view) {
    this -> view = view;
}

void Controller::startGame() {
    int choice;
    view.greeting();
    view.promptForHoldOrHit();
    cin >> choice;
    while(choice != 1 && choice != 2) {
        view.promptForHoldOrHit();
        cin >> choice;
    }
    
}
