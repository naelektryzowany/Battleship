#include "Coordinates2d.h"
#include <algorithm>
#include <iostream>

std::vector<int> Coordinates2d::getCoordinates(void) const {
  return mCoordinates;
}

bool Coordinates2d::operator==(const CoordinatesIf &rhs) const {
    std::vector<int> rhsCoordinates = rhs.getCoordinates();
    bool isEqual = false;
    if(mDimension == rhsCoordinates.size()) {
        isEqual = std::equal(mCoordinates.begin(), mCoordinates.end(), rhsCoordinates.begin());
    }
    return isEqual;
}