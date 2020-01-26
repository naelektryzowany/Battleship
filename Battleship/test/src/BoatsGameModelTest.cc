#include "BoatsGameModel.h"
#include "gtest/gtest.h"
#include <iostream>

class BoatsGameModelTest : public ::testing::Test {
  protected :
    std::vector<int> mCoordinateXYFirst{1,1};
    std::vector<int> mCoordinateXYSecond{1,2};
    Coordinates2d mCordinatesForMastFirst{mCoordinateXYFirst};
    Coordinates2d mCordinatesForMastSecond{mCoordinateXYSecond};
    std::vector<Coordinates2d> mShipCoordinates{mCoordinateXYFirst, mCoordinateXYSecond};
    std::vector<std::vector<Coordinates2d>> mShipsCoordinates{mShipCoordinates};
};
