//
//  Model.hpp
//  Black_Jack
//
//  Created by Yunpeng Gao on 4/9/17.
//  Copyright © 2017 Yunpeng Gao. All rights reserved.
//

#ifndef Model_hpp
#define Model_hpp

#include <iostream>
#include <time.h>
#include <sstream>

using namespace std;
//#include <string>

class Model {
	public:
	int ** deck = NULL;
	int playerHand[10];
	int dealerHand[10];
	int playerHandSize = 0;
	int dealerHandSize = 0;
	int playerScore = 0;
	int dealerScore = 0;
	int numPlayers = 1;
	bool endGame = 0;
	string faceDownCard;
	//private:
	void initDeck();
	void dealOpeningHands();
	void dealerTurn();
	void playerTurn();
	void playRound();
	void updateScores();
	string drawCard(int currentPlayer);
	int determineWinner();
};

#endif /* Model_hpp */
