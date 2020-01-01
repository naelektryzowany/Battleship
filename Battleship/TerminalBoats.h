#ifndef TERMINAL_BOATS_H
#define TERMINAL_BOATS_H
#include "GameStrategyIf.h"
#include "Coordinates2d.h"
#include "TerminalBoard.h"
#include "BoatsGameModel.h"

class TerminalBoats : public GameStrategyIf {
    public:
    TerminalBoats() = default;
    TerminalBoats(const TerminalBoats&) = delete;
    TerminalBoats(TerminalBoats&&) = delete;
    TerminalBoats& operator=(const TerminalBoats&) = delete;
    TerminalBoats& operator=(TerminalBoats&&) = delete;
    ~TerminalBoats();
    virtual void prepareToGame();
    virtual void runGame();
    private:
    std::pair<int,int> getBoardSize();
    std::vector<std::vector<Coordinates2d>> getShipCoordinares();
    int readNumberOfMasts();
    std::vector<Coordinates2d> readMastCoordinates(int masts, bool isHorizontal);
    bool checkIfCoordinatesFitInBoard(Coordinates2d coordinates);
    int readIntegerValue(std::string prompt);
    Coordinates2d getHitCoordinates();
    void transformStringToCorrectFormat(std::string& stringToCorrect);
    bool checkIfAnyCollisionExists(std::vector<Coordinates2d> coordinateToCheck, std::vector<std::vector<Coordinates2d>> shipCoordinates);
    bool getDecisionFromUser(std::string prompt);
    GameModelIf* mGame = nullptr;
    SurfaceIf * mBoard = nullptr;
    std::pair<int, int> mBoardSize;
};

#endif