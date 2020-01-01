#ifndef COORDINATES_FACTORY_IF_H
#define COORDINATES_FACTORY_IF_H
#include "CoordinatesIf.h"
#include <memory>

class CoordinatesFactoryIf {
    public:
    virtual std::unique_ptr<CoordinatesIf> createNewCoordinates(std::vector<int> generiCoordinates) const = 0;
};

#endif