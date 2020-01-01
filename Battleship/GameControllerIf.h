#ifndef GAME_CONTROLLER_IF
#define GAME_CONTROLLER_IF

class GameControllerIf {
    public:
    virtual void prepareToGame() = 0;
    virtual void runGame() = 0;
};

#endif