#ifndef TERMINAL_BOARD_H
#define TERMINAL_BOARD_H
#include "SurfaceIf.h"
#include "Coordinates2d.h"

class TerminalBoard : public SurfaceIf {
    public :
    TerminalBoard(std::vector<std::vector<Coordinates2d>> shipCoordinates, int width, int height, char shipRepresentation, char boardRepresentation, char hitRepresentation);
    virtual void draw() const;
    virtual void updateSurface(const CoordinatesIf& coordinate);
    virtual void printActualScore(GameData gameData);
    virtual void printEndScore(GameData gameData) const;
    private :
    void drawOnSurface(const CoordinatesIf& coordinate, char pixelRepresentation);
    void resetLastHitInfo();
    std::vector<std::vector<char>> mBoard;
    char mBoardRepresentation;
    char mShipRepresentation;
    char mHitRepresentation;
};

#endif