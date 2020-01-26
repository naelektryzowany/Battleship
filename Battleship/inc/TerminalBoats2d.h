#ifndef TERMINAL_BOATS_2_D_H
#define TERMINAL_BOATS_2_D_H
#include "GameStrategyIf.h"
#include "Coordinates2d.h"
#include "TerminalBoard.h"
#include "BoatsGameModel.h"

class TerminalBoats2d : public GameStrategyIf {
    public:
    TerminalBoats2d() = default;
    TerminalBoats2d(const TerminalBoats2d&) = delete;
    TerminalBoats2d(TerminalBoats2d&&) = delete;
    TerminalBoats2d& operator=(const TerminalBoats2d&) = delete;
    TerminalBoats2d& operator=(TerminalBoats2d&&) = delete;
    virtual void prepareToGame();
    virtual void runGame();
    private:
    std::pair<int,int> getBoardSize();
    std::vector<std::vector<Coordinates2d>> getShipCoordinares();
    int readNumberOfMasts();
    std::vector<Coordinates2d> readMastCoordinates(int masts, bool isHorizontal);
    bool checkIfCoordinatesFitInBoard(Coordinates2d& coordinates);
    int readIntegerValue(std::string &prompt);
    Coordinates2d getHitCoordinates();
    void transformStringToCorrectFormat(std::string& stringToCorrect);
    bool checkIfAnyCollisionExists(std::vector<Coordinates2d> coordinateToCheck, std::vector<std::vector<Coordinates2d>> shipCoordinates);
    bool getDecisionFromUser(std::string &prompt);
    std::vector<std::vector<std::shared_ptr<CoordinatesIf>>> coordinates2dToGeneric(std::vector<std::vector<Coordinates2d>> coordinates) const;
    std::unique_ptr<GameModelIf> mGame = nullptr;
    std::unique_ptr<SurfaceIf> mBoard = nullptr;
    std::pair<int, int> mBoardSize;
};

#endif
