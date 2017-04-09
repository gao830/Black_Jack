#ifndef Model_hpp
#define Model_hpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
using namespace std;

class Model {
	public:
	int deck[4][13];
	int playerHand[10];
	int dealerHand[10];
	int playerHandSize = 0;
	int dealerHandSize = 0;
	private:
	void initDeck();
	void drawCard(int currentPlayer);
	void determineWinner();

};



#endif /* Model_hpp */
