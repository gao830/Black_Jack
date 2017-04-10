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
private:
    View view;
};



#endif /* Controller_hpp */
