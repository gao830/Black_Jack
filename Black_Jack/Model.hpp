//
//  Model.hpp
//  Black_Jack
//
//  Created by Yunpeng Gao on 4/9/17.
//  Copyright © 2017 Yunpeng Gao. All rights reserved.
//

#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>

class Model {
	public:
	int deck[4][13];
	int playerHand[10];
	int dealerHand[10];
	int playerHandSize = 0;
	int dealerHandSize = 0;
	private:
	void initDeck();
	string drawCard(int currentPlayer);
	int determineWinner();

};



#endif /* Model_hpp */
