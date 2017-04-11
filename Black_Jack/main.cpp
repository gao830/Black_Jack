#include <iostream>
#include "View.hpp"
#include "Controller.hpp"
#include "Model.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
//    View view;
//    Controller controller(view);
//    controller.startGame();
    srand(time(NULL));
    int playGames = 1;
    Model model;
    
    while(playGames == 1){
        model.playRound();
        cout << "Do you want to play it again? (1 for yes, 2 for no)" << endl;
        cin >> playGames;
    }
    return 0;
}
