#include "Ship2d.h"
#include <algorithm>
#include <utility>

Ship2d::Ship2d(std::vector<Coordinates2d> coordinates) {
    for(const auto &element : coordinates) {
        ShipMast mast(element);
        mMasts.push_back(mast);
    }
}
std::vector<std::reference_wrapper<const CoordinatesIf>> Ship2d::getCoordinates() const {
    std::vector<std::reference_wrapper<const CoordinatesIf>> coordinatesToReturn;
    for(const auto &element : mMasts) {
       const Coordinates2d &temp = element.getCoordinates();
        coordinatesToReturn.push_back(temp);
    }
    return coordinatesToReturn;
}

bool Ship2d::getStatus() const {
    return mStatus;
}

void Ship2d::hit(CoordinatesIf& coordinate) {
    for(auto& mast: mMasts) {
        if(coordinate == mast.getCoordinates()) {
            mast.setStatus(false);
        }
    }
    mStatus = computestatus();
}

bool Ship2d::computestatus() const {
    return !std::all_of(mMasts.begin(), mMasts.end(), [](ShipMast mast) {return mast.getStatus() == false;});
}