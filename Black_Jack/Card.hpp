//
//  Card.hpp
//  Black_Jack
//
//  Created by Yunpeng Gao on 4/17/17.
//  Copyright © 2017 Yunpeng Gao. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Card {
public:
    string card[9];
    
    void setCard(string character, int suit);
    void displayCard();
};



#endif /* Card_hpp */
