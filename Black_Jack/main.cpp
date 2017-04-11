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
    Model model;
    model.playRound();
    return 0;
}
