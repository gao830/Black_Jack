#include <iostream>
#include "View.hpp"
#include "Controller.hpp"
#include "Model.hpp"
#include "Card.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    Card card;
//    card.setCard("K", 3);
//    card.displayCard();
    srand(unsigned(time(NULL)));
    int playGames = 1;
    Model model;
    
    while(playGames == 1){
        model.playRound();
        cout << "Do you want to play it again? (1 for yes, 2 for no)" << endl;
        cin >> playGames;
        model.clear();
    }
    return 0;
}
