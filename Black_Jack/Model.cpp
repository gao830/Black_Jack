//
//  Model.cpp
//  Black_Jack
//
//  Created by Yunpeng Gao on 4/9/17.
//  Copyright © 2017 Yunpeng Gao. All rights reserved.
//

#include "Model.hpp"

void Model::initDeck() {
	for(int i = 0; i++; i < 4) {
		for(int j = 0; j++; j < 13) {
			deck[i][j] = j+2;
		}
	}
}

//currentPlayer = 0 for dealer and currentPlayer = 1 for player
string Model::drawCard(currentPlayer) {
	srand(time(NULL));
	string cardDrawn;
	int suit = rand() % 4;
	int card = rand() % 13;
	int chosenCard = deck[suit][card];
	if(currentPlayer == 0) {
		dealerHand[dealerHandSize] = chosenCard;
		dealerHandSize++:
	}
	if(currentPlayer == 1) {
		playerHand[playerHandSize] = chosenCard;
		playerHandSize++;
	}
	string faceCard;
	switch (chosenCard) {
		case 10:
			faceCard = "T";
			break;
		case 11:
			faceCard = "J";
			break;
		case 12:
			faceCard = "Q";
			break;
		case 13:
			faceCard = "K";
			break;
		case 14:
			faceCard = "K";
			break;
		default:
			faceCard = numberToString(chosenCard);
	}
	switch (suit) {
		case 0:
			cardDrawn = "Heart: " + faceCard;
			break;
		case 1:
			cardDrawn = "Diamond: " + faceCard;
			break;
		case 2:
			cardDrawn = "Spade: " + faceCard;
			break;
		case 3:
			cardDrawn =  "Clubs: " + faceCard;
			break;

	}
	return cardDrawn;
}
//Returns 0 for draw, 1 for dealer win, 2 for player win
int Model::determineWinner() {
	int playerScore;
	int dealerScore;

	for(int i = 0; i < playerHandSize; i++) {
		if(playerHand[i] < 11) {
			playerScore += playerHand[i];
		}
		if(playerHand[i] > 10 && playerHand[i] < 14) {
			playerScore += 10;
		}
		if(playerHand[i] == 14) {
			playerScore += 11;
		}
	}
	for(int i = 0; i < dealerHandSize; i++) {
		if(dealerHand[i] < 11) {
			dealerScore += dealerHand[i];
		}
		if(dealerHand[i] > 10 && dealerHand[i] < 14) {
			dealerScore += 10;
		}
		if(dealerHand[i] == 14) {
			dealerScore += 11;
		}
	}
	if(playerScore == dealerScore) {
		return 0;
	}
	if(playerScore < dealerScore) {
		return 1;
	}
	if(playerScore > dealerScore) {
		return 2;
	}
}
