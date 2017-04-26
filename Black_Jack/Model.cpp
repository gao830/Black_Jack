#include "Model.hpp"

void Model::initDeck() {
    deck = new int *[4];
    for (int i = 0; i < 4; i++) {
        deck[i] = new int[13];
        
        //populate the table
        for (int j = 0; j < 13; j++) {
            deck[i][j] = j + 2;
        }
    }
}

void Model::initAIHands() {
	//create a new hand of size 10 for each ai player
	playerAIHands = new int *[numPlayers];
	for (int i = 0; i < numPlayers; i++) {
		playerAIHands[i] = new int[10];
		playerAIHandSize[i] = 0;
		playerAIStand[i] = 0;
		//initialize card values to 0
		for (int j = 0; j < 10; j++) {
			playerAIHands[i][j] = 0;
		}
	}
}

void Model::giveHint() {
	updateScores();
	if (playerScore <= 15) {
		cout << "You should hit." << endl;
	}
	else if (playerScore >= 18) {
		cout << "You should stand." << endl;
	}
	else if (dealerScore >= 17) {
		cout << "You should hit." << endl;
	}
	else if (dealerScore <= 17) {
		cout << "You should stand." << endl;
	}
}

//currentPlayer = 0 for dealer and currentPlayer = 1 for player and currentPlayer = 2 for split
string Model::drawCard(int currentPlayer) {
    //need to implement a way to keep track of which cards have been drawn
    string cardDrawn;
    int suit = rand() % 4;
    int card = rand() % 13;
    int chosenCard = deck[suit][4];
    if(currentPlayer == 0) {
        dealerHand[dealerHandSize] = chosenCard;
        dealerHandSize++;
    }
    if(currentPlayer == 1) {
        playerHand[playerHandSize] = chosenCard;
        playerHandSize++;
		if(playerHandSize == 2) {
			if(playerHand[0] == playerHand[1]) {
				splitAbility = 1;
			}
		}
    }
	if(currentPlayer == 2) {
		playerSplitHand[playerSplitHandSize] = chosenCard;
		playerSplitHandSize++;
	}
	if(currentPlayer > 2 && currentPlayer < numPlayers + 3) {
		for (int i = 0; i < 10; i++) {
			playerAIHands[currentPlayer - 3][i] = chosenCard;
		}
		playerAIHandSize[currentPlayer - 3]++;
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
            faceCard = "A";
            break;
        default:
            ostringstream convert;
            convert << chosenCard;
            faceCard = convert.str();
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
    if(faceCard == "T"){
        faceCard = "10";
    }
    card_type.setCard(faceCard, suit);
    return cardDrawn;
}

//Returns 0 for draw, 1 for dealer win, 2 for player win
int Model::determineWinner(int betAmount) {
    updateScores();
    
    //player goes bust
    if (playerScore > 21 && dealerScore <= 21) {
        totalMoney = totalMoney - betAmount;
        return 1;
    }
    
    //dealer goes bust
    if (dealerScore > 21 && playerScore <= 21) {
        totalMoney = totalMoney + betAmount;
        return 2;
    }

    if(split == 1) {
		if(playerSplitScore == dealerScore) {
 
		} else if(playerSplitScore < dealerScore) {
			totalMoney = totalMoney - betAmount;
			
		} else {
			totalMoney = totalMoney + betAmount;
			
		}
	}
	
    if(playerScore == dealerScore) {
        return 0;
    } else if(playerScore < dealerScore) {
        totalMoney = totalMoney - betAmount;
        return 1;
    } else {
        totalMoney = totalMoney + betAmount;
        return 2;
    }
	
}

//updates the current scores
//call this function at the beginning of each Turn function
void Model::updateScores() {
    playerScore = 0;
    dealerScore = 0;
    playerSplitScore = 0;
	for (int i = 0; i < numPlayers; i++) {
		playerAIScore[i] = 0;
	}

    for (int i = 0; i < playerHandSize; i++) {
        if (playerHand[i] < 11) {
            playerScore += playerHand[i];
        }
        if (playerHand[i] > 10 && playerHand[i] < 14) {
            playerScore += 10;
        }
        if (playerHand[i] == 14) {
            playerScore += 11;
        }
    }
    for (int i = 0; i < dealerHandSize; i++) {
        if (dealerHand[i] < 11) {
            dealerScore += dealerHand[i];
        }
        if (dealerHand[i] > 10 && dealerHand[i] < 14) {
            dealerScore += 10;
        }
        if (dealerHand[i] == 14) {
            dealerScore += 11;
        }
    }
	for (int i = 0; i < numPlayers; i++) {
		//i is the ai player number
		//j represents a card in their hand
		//check each card in the hand
		for (int j = 0; j < playerAIHandSize[i]; j++) {
			if (playerAIHands[i][j] < 11) {
				playerAIScore[i] += playerAIHands[i][j];
			}
			if (playerAIHands[i][j] > 10 && playerAIHands[i][j] < 14) {
				playerAIScore[i] += 10;
			}
			if (playerAIHands[i][j] == 14) {
				playerAIScore[i] += 11;
			}
		}
	}
	if(split == 1) {
		for (int i = 0; i < playerSplitHandSize; i++) {
			if (playerSplitHand[i] < 11) {
				playerSplitScore += playerSplitHand[i];
			}
			if (playerSplitHand[i] > 10 && playerSplitHand[i] < 14) {
				playerSplitScore += 10;
			}
			if (playerSplitHand[i] == 14) {
				playerSplitScore += 11;
			}
		}
	}
	
    
}

//initializes the opening hands
//these cards should be displayed in the view, not here
void Model::dealOpeningHands() {
    cout << "Opening hands!" << endl;
    
    string displayMe;

	displayMe = drawCard(1);
	card_type.displayCard();
	cout << "You're dealt " << displayMe << endl;
	cout << endl;

    for (int i = 0; i < numPlayers; i++) {
		displayMe = drawCard(i + 3);
		card_type.displayCard();
		cout << "COM" << i << " was dealt " << displayMe << endl;
		cout << endl;
    }
    
    displayMe = drawCard(0);
    card_type.displayCard();
    cout << "Dealer draws " << displayMe << endl;
    cout << endl;

	displayMe = drawCard(1);
	card_type.displayCard();
	cout << "You're dealt " << displayMe << endl;
	cout << endl;
    
    for (int i = 0; i < numPlayers; i++) {
		displayMe = drawCard(i + 3);
		card_type.displayCard();
		cout << "COM" << i << " was dealt " << displayMe << endl;
		cout << endl;
    }
    
    faceDownCard = drawCard(0);
}

//the dealer takes their turn
//these cards should be displayed in the view, not here
void Model::dealerTurn() {
    cout << endl;
    cout << "Dealer's turn!" << endl;
    
    updateScores();
    
    string displayMe;
    if (dealerScore >= 21) {
        endGame = true;
        return;
    }
    else if(dealerScore <= 16) {
        cout << "Dealer hits." << endl;
        displayMe = drawCard(0);
        card_type.displayCard();
        cout << "Dealer draws " << displayMe << endl;
        cout << endl;
        updateScores();
    }
    else {
        cout << "Dealer stands." << endl;
        dealerStand = true;
    }
}

//the player takes their turn
//the prompt should be in the view, but I'm putting it here for now
void Model::playerTurn() {
    cout << endl;
    cout << "Your turn!" << endl;
    
    updateScores();
    cout << "Your total: " << playerScore << endl;
//    cout << playerHand[0] << endl;
//    cout << playerAIScore[1] << endl;
//    cout << playerAIScore[2] << endl;
//    cout << playerAIScore[3] << endl;

    if (playerScore >= 21) {
        endGame = true;
        return;
    }
    //    for(int i=0; i<9; i++){
//        cout << "│\t\t│\t\t│\t\t│\t\t│\t\t│" << endl;
//    }
//    cout<<endl;
    if(chartNum == 1) {
        chart();
        chartNum = 0;
    }
    
    char action;
	bool actionTaken = false;
    string displayMe;
    
    cout << "Type s to stand, h to hit, or ? for a hint." << endl;
	if(splitAbility == 1) {
		cout << "Type x to split." << endl;
	}
    cin >> action;
    
	while (!actionTaken) {
		switch (action) {
		case 's':
			playerStand = true;
			actionTaken = true;
			break;
		case 'h':
			displayMe = drawCard(1);
			card_type.displayCard();
			cout << "You're dealt " << displayMe << endl;
			cout << endl;
			actionTaken = true;
			break;
		case '?':
			giveHint();
            actionTaken = true;
			break;
		case 'x':
		    split = 1;
			splitCards();
			actionTaken = true;
			break;
		}
	}
}

void Model::playerAITurn(int currentPlayer) {
	updateScores();
	string displayMe;
	//for (int i = 0; i < numPlayers; i++) {

		cout << "COM" << currentPlayer << "'s turn!" << endl;

		//aggressive
		if (currentPlayer % 2 == 0) {
			cout << "COM" << currentPlayer << " hits." << endl;
			displayMe = drawCard(currentPlayer + 3);
			card_type.displayCard();
			cout << "COM" << currentPlayer << " draws " << displayMe << endl;
			cout << endl;
			updateScores();
			if (playerAIScore[currentPlayer] > 21) {
				cout << "COM" << currentPlayer << " went bust!" << endl;
				playerAIBust[currentPlayer] = true;
			}
		}

		//reasonable
		else {
			if (playerAIScore[currentPlayer] <= 15) {
				cout << "COM" << currentPlayer << " hits." << endl;
				displayMe = drawCard(currentPlayer + 3);
				card_type.displayCard();
				cout << "COM" << currentPlayer << " draws " << displayMe << endl;
				cout << endl;
				updateScores();
				if (playerAIScore[currentPlayer] > 21) {
					cout << "COM" << currentPlayer << " went bust!" << endl;
					cout << playerAIScore[currentPlayer] << endl;
					playerAIBust[currentPlayer] = true;
				}
			}
			else if (playerAIScore[currentPlayer] >= 18) {
				cout << "COM" << currentPlayer << " stands." << endl;
				playerAIStand[currentPlayer] = 1;
			}
			else if (dealerScore >= 17) {
				cout << "COM" << currentPlayer << " hits." << endl;
				displayMe = drawCard(currentPlayer + 3);
				card_type.displayCard();
				cout << "COM" << currentPlayer << " draws " << displayMe << endl;
				cout << endl;
				updateScores();
				if (playerAIScore[currentPlayer] > 21) {
					cout << "COM" << currentPlayer << " went bust!" << endl;
					playerAIBust[currentPlayer] = true;
				}
			}
			else if (dealerScore <= 17) {
				cout << "COM" << currentPlayer << " stands." << endl;
				playerAIStand[currentPlayer] = 1;
			}
		}
	//}
}

//contains the loop for playing the game
void Model::playRound() {
    int result;
    initDeck();
	initAIHands();

    cout << "Total money: " << getTotalMoney() << endl;
    cout << "Scoreboard: " << getWinTimes() << " - " << getLoseTimes() << endl;
    cout << "Balance: " << getTotalMoney() - 100 << endl;
    
    setBetAmount();
    dealOpeningHands();
    
    while (!endGame) {
		if (!playerStand) {
			playerTurn();
		}

		//after the player stands, the ai take turns
        if(playerStand) {
			
			//keep going until each ai player has stood
			for (int i = 0; i < numPlayers; i++) {
				while (!playerAIBust[i] && !playerAIStand[i]) {
					playerAITurn(i);
					//cout << playerAIScore[i] << endl;
				}
			}

			dealerTurn();
        }
        if (dealerStand && playerStand) {
            endGame = true;
        }
    }
    
    updateScores();
    result = determineWinner(betAmount);
    
    if (result == 0) {
        cout << "Tie!" << endl;
    }
    else if (result == 1) {
        cout << "Dealer wins!" << endl;
        lose++;
    }
    else if (result == 2) {
        cout << "Player wins!" << endl;
        win++;
    }
    
    cout << "Dealer score: " << dealerScore << endl;
}

int Model::getPlayerScore() {
    return playerScore;
}
int Model::getDealerScore() {
    return dealerScore;
}
int Model::getTotalMoney() {
    return totalMoney;
}

int Model::getWinTimes() {
    return win;
}

int Model::getLoseTimes() {
    return lose;
}

void Model::setBetAmount() {
	int bet = 0;
	cout << "Input the amount you wish to bet: " << endl;
	cin >> bet;
	betAmount = bet;
	cout << "The amount you chose to bet was: " << betAmount << endl;
}

void Model::clear() {
    for (int i = 0; i < 9; i++){
        playerHand[i] = 0;
        dealerHand[i] = 0;
		playerSplitHand[i] = 0;
    }
    chartNum = 1;
    betAmount = 0;
    playerHandSize = 0;
    dealerHandSize = 0;
    playerScore = 0;
    dealerScore = 0;
	playerSplitScore = 0;
	split = 0;
	splitAbility = 0;
    endGame = 0;
    dealerStand = 0;
    playerStand = 0;
	for (int i = 0; i < numPlayers; i++) {
		playerAIBust[i] = false;
		playerAIStand[i] = false;
	}
	playerSplitHandSize = 0;
	playerSplitStand = false;
}

void Model::splitCards() {
	playerSplitHand[0] = playerHand[1];
	playerHand[1] = 0;
	playerHandSize--;
	playerSplitHandSize++;
	drawCard(2);
	while (!playerSplitStand) {
		playerSplitTurn();
	}
}


void Model::chart() {
    cout<<"┌";
    for(int j=0; j<numPlayers+2; j++){
        for(int i=0; i<12; i++){
            cout << "─";
        }
        if (j==numPlayers+1){
            cout << "┐";
        } else {
            cout << "┬";
        }
        
    }
    cout << endl;
    cout << "│            " <<"│   Player   ";
    for (int i = 0; i< numPlayers; i++) {
        cout << "│   COM" << i << "     ";
    }
    cout << "│" << endl;
    cout<<"├";
    
    for(int j=0; j<numPlayers+2; j++){
        for(int i=0; i<12; i++){
            cout << "─";
        }
        if (j == numPlayers+1){
            cout<<"┤"<<endl;
        } else {
            cout << "┼";
        }
        
    }
    
    
    cout << "│ 1st dealt  " <<"│      "<<playerHand[0]<<"     ";
    for (int i = 0; i< numPlayers; i++) {
        cout << "│      " << playerAIHands[i][0] << "     ";
    }
    cout << "│" << endl;
    cout<<"├";
    for(int j=0; j<numPlayers+2; j++){
        for(int i=0; i<12; i++){
            cout << "─";
        }
        if (j == numPlayers+1){
            cout<<"┤"<<endl;
        } else {
            cout << "┼";
        }
        
    }
    
    cout << "│ 2nd dealt  " <<"│      "<<playerHand[1]<<"     ";
    for (int i = 0; i< numPlayers; i++) {
        cout << "│      " << playerAIHands[i][1] << "     ";
    }
    cout << "│" << endl;
    cout<<"├";
    for(int j=0; j<numPlayers+2; j++){
        for(int i=0; i<12; i++){
            cout << "─";
        }
        if (j == numPlayers+1){
            cout<<"┤"<<endl;
        } else {
            cout << "┼";
        }
        
    }
    cout << "│   Total    " <<"│     "<<playerScore<<"     ";
    for (int i = 0; i< numPlayers; i++) {
        cout << "│     " << playerAIScore[i] << "     ";
    }
    cout << "│" << endl;
    cout<<"└";
    for(int j=0; j<numPlayers+2; j++){
        for(int i=0; i<12; i++){
            cout << "─";
        }
        if (j == numPlayers+1){
            cout << "┘";
        } else {
            cout <<"┴";
        }
    }
    
    cout<<endl;

}

void Model::playerSplitTurn() {
    cout << endl;
    cout << "Your turn!" << endl;
   
    updateScores();
    cout << "Your total: " << playerSplitScore << endl;
    
    if (playerSplitScore >= 21) {
		playerSplitStand = true;
        return;
    }
    
    char action;
	bool actionSplitTaken = false;
    string displayMe;
        
	cout << "Split Hand" << endl;
    cout << "Type s to stand, h to hit, or ? for a hint." << endl;
	
    cin >> action;
    
	while (!actionSplitTaken) {
		switch (action) {
		case 's':
			playerSplitStand = true;
			actionSplitTaken = true;
			break;
		case 'h':
			displayMe = drawCard(2);
			card_type.displayCard();
			cout << "You're dealt " << displayMe << endl;
			cout << endl;
			actionSplitTaken = true;
			break;
		case '?':
			giveHint();
            actionSplitTaken = true;
			break;
		case 'x':
			splitCards();
			actionSplitTaken = true;
			break;
		}
	}
}
