#include <iostream>
#include "View.hpp"
#include "Controller.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    View view;
    Controller controller(view);
    controller.startGame();
    return 0;
}
