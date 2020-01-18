#include "ShipMast.h"

const Coordinates2d& ShipMast::getCoordinates() const {
    return mCoordinates;
}

bool ShipMast::getStatus() const {
    return mIsOperational;
}

void ShipMast::setStatus(bool newStatus) {
    mIsOperational = newStatus;
}