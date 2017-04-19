//
//  Card.cpp
//  Black_Jack
//
//  Created by Yunpeng Gao on 4/17/17.
//  Copyright © 2017 Yunpeng Gao. All rights reserved.
//

#include "Card.hpp"

void Card::setCard(string character, int suit) {
    string character2 = character;
    if (character != "10") {
        
        character = character + " ";
        character2 = " " + character2;
        
    }
    string suit_type;
    switch (suit) {
        case 0:
            suit_type = "♥";
            break;
        case 1:
            suit_type = "♦";
            break;
        case 2:
            suit_type = "♠";
            break;
        case 3:
            suit_type =  "♣";
            break;
            
    }
    
	card[0] = "┌─────────┐";
	card[1] = "│" + character + "       │";
    card[2] = "│         │";
    card[3] = "│         │";
    card[4] = "│    " + suit_type +"    │";
    card[5] = "│         │";
    card[6] = "│         │";
    card[7] = "│       " + character2 + "│";
    card[8] = "└─────────┘";
    
}

void Card::displayCard() {
    cout << card[0] << endl;
    cout << card[1] << endl;
    cout << card[2] << endl;
    cout << card[3] << endl;
    cout << card[4] << endl;
    cout << card[5] << endl;
    cout << card[6] << endl;
    cout << card[7] << endl;
    cout << card[8] << endl;
}
