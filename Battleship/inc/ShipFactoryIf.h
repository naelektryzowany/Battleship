#ifndef SHIP_FACTORY_IF_H
#define SHIP_FACTORY_IF_H
#include "ShipIf.h"
#include "CoordinatesIf.h"
#include <memory>

class ShipFactoryIf {
    public:
    virtual std::unique_ptr<ShipIf> createNewShip(std::vector<std::shared_ptr<CoordinatesIf>> generiCoordinates) const = 0;
};

#endif