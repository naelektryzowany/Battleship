#ifndef BOATS_GAME_H
#define BOATS_GAME_H
#include "GameControllerIf.h"
#include "GameStrategyIf.h"



class BoatsGame : public GameControllerIf {
    public:
    explicit BoatsGame(GameStrategyIf *gameStrategy) : mGameStrategy(gameStrategy) {}
    BoatsGame(const BoatsGame&) = delete;
    BoatsGame(BoatsGame&&) = delete;
    BoatsGame& operator=(const BoatsGame&) = delete;
    BoatsGame& operator=(BoatsGame&&) = delete;
    ~BoatsGame();
    virtual void prepareToGame();
    virtual void runGame();
    private:
    GameStrategyIf *mGameStrategy = nullptr;
};

#endif
