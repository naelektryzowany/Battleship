#include <iostream>
#include "Coordinates2d.h"
#include "BoatsGameModel.h"
#include "TerminalBoard.h"
#include "BoatsGame.h"
#include "TerminalBoats2d.h"

//g++ main.cc ShipMast.h ShipMast.cc  CoordinatesIf.h Coordinates2d.h Coordinates2d.cc ShipIf.h Ship2d.h Ship2d.cc GameData.h GameData.cc GameModelIf.h BoatsGameModel.h BoatsGameModel.cc  SurfaceIf.h TerminalBoard.h TerminalBoard.cc GameControllerIf.h BoatsGame.h BoatsGame.cc -o game -std=c++11

int main(void) {

    GameControllerIf* game = new BoatsGame(new TerminalBoats2d);
    game->prepareToGame();
    game->runGame();
    return 0;
}