#ifndef Controller_hpp
#define Controller_hpp

#include <iostream>
#include <stdio.h>
#include "View.hpp"
#include "Model.hpp"
using namespace std;

class Controller {
public:
    Controller(View &view);
    void startGame();
    void hitOrHold();
private:
    View view;
    Model model;
    string cardDrawn;
    int playerScore;
};



#endif /* Controller_hpp */
