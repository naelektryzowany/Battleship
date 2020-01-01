#ifndef SHIP_2_D_FACTORY_H
#define SHIP_2_D_FACTORY_H
#include "ShipFactoryIf.h"
#include "CoordinatesIf.h"

class Ship2dFactory : public ShipFactoryIf {
    public:
    virtual std::unique_ptr<ShipIf> createNewShip(std::vector<std::shared_ptr<CoordinatesIf>> generiCoordinates) const;
};

#endif