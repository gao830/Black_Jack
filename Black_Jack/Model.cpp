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

//currentPlayer = 0 for dealer and currentPlayer = 1 for player
string Model::drawCard(int currentPlayer) {
    //need to implement a way to keep track of which cards have been drawn
    string cardDrawn;
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
    return cardDrawn;
}

//Returns 0 for draw, 1 for dealer win, 2 for player win
int Model::determineWinner(int betAmount) {
    updateScores();
    
    //player goes bust
    if (playerScore > 21 && dealerScore <= 21) {
        return 1;
    }
    
    //dealer goes bust
    if (dealerScore > 21 && playerScore <= 21) {
        return 2;
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
    
}

//initializes the opening hands
//these cards should be displayed in the view, not here
void Model::dealOpeningHands() {
    cout << "Opening hands!" << endl;
    
    string displayMe;
    for (int i = 0; i < numPlayers; i++) {
        displayMe = drawCard(1);
        cout << "You're dealt " << displayMe << endl;
    }
    
    displayMe = drawCard(0);
    cout << "Dealer draws " << displayMe << endl;
    
    for (int i = 0; i < numPlayers; i++) {
        displayMe = drawCard(1);
        cout << "You're dealt " << displayMe << endl;
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
        cout << "Dealer draws " << displayMe << endl;
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
    
    if (playerScore >= 21) {
        endGame = true;
        return;
    }
    
    char action;
    string displayMe;
    
    cout << "Type s to stand or h to hit." << endl;
    cin >> action;
    
    switch (action) {
        case 's':
            playerStand = true;
            break;
        case 'h':
            displayMe = drawCard(1);
            cout << "You're dealt " << displayMe << endl;
            break;
    }
}

//contains the loop for playing the game
void Model::playRound() {
    int result;
    initDeck();
    dealOpeningHands();
    
    while (!endGame) {
        if(!playerStand) {
            playerTurn();
        }
        if(playerStand) {
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
    }
    else if (result == 2) {
        cout << "Player wins!" << endl;
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
