#include "Controller.hpp"

Controller::Controller(View &view) {
    this -> view = view;
}

void Controller::startGame() {
    cout << "Hello world" << endl;
}
