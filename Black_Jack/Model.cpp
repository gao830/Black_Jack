#include "Model.hpp"

void Model::initDeck() {
    for(int i = 0; i < 4; i++ ) {
        for(int j = 0;  j < 13; j++) {
			deck[i][j] = j+2;
		}
	}
}

void Model::drawCard(int currentPlayer) {
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
	char faceCard;
	switch (card) {
		case 10:
			faceCard = 'T';
			break;
		case 11:
			faceCard = 'J';
			break;
		case 12:
			faceCard = 'Q';
			break;
		case 13:
			faceCard = 'K';
			break;
		case 14:
			faceCard = 'A';
			break;
		default:
			faceCard = char(card);
	}
	switch (suit) {
		case 0:
			cout << "Heart: " << faceCard  << endl;
			break;
		case 1:
			cout << "Diamond: " << faceCard << endl;
			break;
		case 2:
			cout << "Spade: " << faceCard << endl;
			break;
		case 3:
			cout << "Clubs: "<< faceCard << endl;
			break;

	}

}

void Model::determineWinner() {
	int playerScore = 0;
	int dealerScore = 0;

	for(int i = 0; i < playerHandSize; i++) {
		playerScore += playerHand[i];
	}
	for(int i = 0; i < dealerHandSize; i++) {
        dealerScore += dealerHand[i];
	}
	if(playerScore == dealerScore) {
		//Draw
	}
	if(playerScore < dealerScore) {
		//Lose
	}
	if(playerScore > dealerScore) {
		//Win
	}
}
