#ifndef View_hpp
#define View_hpp

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class View {
public:
    View();
    void greeting();
    void promptForHoldOrHit();
    void displayWinner(int identifier);
    void displayCardDrawnAndScore(int score, string cardDrawn);
};


#endif /* View_hpp */
