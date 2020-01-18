#ifndef SURFACE_IF_H
#define SURFACE_IF_H
#include "CoordinatesIf.h"
#include "GameData.h"

class SurfaceIf {
    public :
    virtual void draw() const = 0;
    virtual void updateSurface(const CoordinatesIf& coordinate) = 0;
    virtual void printActualScore(GameData gameData) = 0;
    virtual void printEndScore(GameData gameData) const = 0;
};

#endif