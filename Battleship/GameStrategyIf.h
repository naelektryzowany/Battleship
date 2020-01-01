#ifndef GAME_STRATEGY_IF_H
#define GAME_STRATEGY_IF_H

class GameStrategyIf {
    public:
    virtual void prepareToGame() = 0;
    virtual void runGame() = 0;
};

#endif