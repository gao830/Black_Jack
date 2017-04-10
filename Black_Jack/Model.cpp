#include "Model.hpp"

void Model::initDeck() {
    for(int i = 0; i < 4; i++ ) {
        for(int j = 0;  j < 13; j++) {
			deck[i][j] = j+2;
		}
	}
}

string Model::drawCard(int currentPlayer) {
//	srand(time(NULL));
    srand( static_cast<unsigned int>(time(NULL)));
	int suit = rand() % 4;
	int card = rand() % 13;
	int chosenCard = deck[suit][card];
	if(currentPlayer == 0) {
		dealerHand[dealerHandSize] = chosenCard;
        dealerHandSize++;
	}
	if(currentPlayer == 1) {
		playerHand[playerHandSize] = chosenCard;
		playerHandSize++;
	}
	string faceCard;
    string cardDrawn;
    
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
			faceCard = to_string(chosenCard);
            
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

int Model::determineWinner() {
    
	int playerScore = 0;
	int dealerScore = 0;

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
        dealerScore += dealerHand[i];
	}
    
	if(playerScore == dealerScore) {
		return 0;
	} else if(playerScore < dealerScore) {
		return 1;
	} else {
		return 2;
	}
}
