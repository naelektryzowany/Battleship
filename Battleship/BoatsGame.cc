#include "BoatsGame.h"

BoatsGame::~BoatsGame() {
    delete mGameStrategy;
}

void BoatsGame::prepareToGame() {
    mGameStrategy->prepareToGame();
}

void BoatsGame::runGame() {
   mGameStrategy->runGame();
}