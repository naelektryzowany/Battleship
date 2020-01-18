#include "Coordinates2dFactory.h"
#include "Coordinates2d.h"

std::unique_ptr<CoordinatesIf> Coordinates2dFactory::createNewCoordinates(std::vector<int> generiCoordinates) const {
    std::unique_ptr<CoordinatesIf> coordinates2d(new Coordinates2d(generiCoordinates));
    return std::move(coordinates2d);
}