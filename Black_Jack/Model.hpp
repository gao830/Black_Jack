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
	int ** playerAIHands;
	int playerAIHandSize[4];
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
	int playerAIScore[4];
	int numPlayers = 4;
    int lose = 0;
    int win = 0;
	int split = 0;
	int splitAbility = 1;
    int chartNum = 1;
    int chartNum2 = 0;
	bool endGame = 0;
	bool dealerStand = 0;
	bool playerStand = 0;
	bool playerAIStand[4];
	bool playerAIBust[4];
	bool playerSplitStand = false;
	bool threeOfAKind = false;
	bool threeInARow = false;
	string faceDownCard;
    Card card_type;
	//private:
	void initDeck();
	void initAIHands();
	void giveHint();
	void dealOpeningHands();
	void dealerTurn();
	void playerTurn();
	void playerAITurn(int currentPlayer);
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
    void chart();
    void chart2();
	void pokerGame();
};

#endif /* Model_hpp */
