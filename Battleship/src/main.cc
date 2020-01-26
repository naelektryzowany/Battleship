#include <iostream>
#include "Coordinates2d.h"
#include "BoatsGameModel.h"
#include "TerminalBoard.h"
#include "BoatsGame.h"
#include "TerminalBoats2d.h"

int main(void) {
    GameControllerIf* game = new BoatsGame(new TerminalBoats2d); // TODO memory leak
    game->prepareToGame();
    game->runGame();
    delete game;
    return 0;
}
