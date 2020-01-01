#ifndef COORDINATES_2_DFACTORY_IF_H
#define COORDINATES_2_DFACTORY_IF_H
#include "CoordinatesFactoryIf.h"

class Coordinates2dFactory : public CoordinatesFactoryIf {
    public:
    virtual std::unique_ptr<CoordinatesIf> createNewCoordinates(std::vector<int> generiCoordinates) const;
};

#endif