#include "Ship2dFactory.h"
#include "Coordinates2d.h"
#include "Ship2d.h"

std::unique_ptr<ShipIf> Ship2dFactory::createNewShip(std::vector<std::shared_ptr<CoordinatesIf>> generiCoordinates) const {
    std::vector<Coordinates2d> ship2dCoordinates;
    for(const auto shipCoordiantes : generiCoordinates) {
        Coordinates2d ship2dCoordinate(shipCoordiantes->getCoordinates());
            ship2dCoordinates.push_back(ship2dCoordinate);
    }
    std::unique_ptr<ShipIf> genericShip(new Ship2d(ship2dCoordinates));
    return std::move(genericShip);
}
