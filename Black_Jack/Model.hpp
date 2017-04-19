#ifndef Model_hpp
#define Model_hpp

#include <iostream>
#include <time.h>
#include <sstream>
#include "Card.hpp"
using namespace std;

class Model {

	public:
	int ** deck = NULL;
	int playerHand[10];
	int playerSplitHand[10];
	int dealerHand[10];
	int totalMoney = 100;
	int betAmount = 0;
	int playerHandSize = 0;
	int dealerHandSize = 0;
	int playerSplitHandSize = 0;
	int playerScore = 0;
	int dealerScore = 0;
	int playerSplitScore = 0;
	int numPlayers = 1;
    int lose = 0;
    int win = 0;
	int split = 0;
	bool endGame = 0;
	bool dealerStand = 0;
	bool playerStand = 0;
	bool playerSplitStand = 0;
	string faceDownCard;
    Card card_type;
	//private:
	void initDeck();
	void giveHint();
	void dealOpeningHands();
	void dealerTurn();
	void playerTurn();
	void playRound();
	void updateScores();
	string drawCard(int currentPlayer);
	int determineWinner(int betAmount);
	int getPlayerScore();
	int getDealerScore();
	int getTotalMoney();
    int getLoseTimes();
    int getWinTimes();
	void setBetAmount();
    void clear();
	void splitCards();
    void playerSplitTurn();
};

#endif /* Model_hpp */
