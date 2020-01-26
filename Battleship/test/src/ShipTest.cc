#include "Ship2d.h"
#include "gtest/gtest.h"
#include <iostream>

class ShipTest : public ::testing::Test {
  protected :
    std::vector<int> mCoordinateXYFirst{1,2};
    std::vector<int> mCoordinateXYSecond{1,3};
    Coordinates2d mCordinatesForMastFirst{mCoordinateXYFirst};
    Coordinates2d mCordinatesForMastSecond{mCoordinateXYSecond};
    std::vector<Coordinates2d> mShipCoordinates{mCordinatesForMastFirst, mCordinatesForMastSecond};
    Ship2d mShipToTest{mShipCoordinates};
};

TEST_F(ShipTest, checkInitialStatusTest)
{
  bool expectedStatus = true;
  bool actualStatus = mShipToTest.getStatus();
  EXPECT_EQ(expectedStatus, actualStatus);
}

TEST_F(ShipTest, checkIfProperCoordinatesAreReturnedTest)
{
  std::vector<int> coordinateXYFirst{1,2};
  std::vector<int> coordinateXYSecond{1,3};
  Coordinates2d cordinatesForMastFirst{coordinateXYFirst};
  Coordinates2d cordinatesForMastSecond{coordinateXYSecond};
  std::vector<Coordinates2d> shipCoordinates{cordinatesForMastFirst, cordinatesForMastSecond};
  Ship2d ship{shipCoordinates};
  std::vector<std::reference_wrapper<const CoordinatesIf>> expectedCoordinates = ship.getCoordinates();
  std::vector<std::reference_wrapper<const CoordinatesIf>> actualCoordinates = mShipToTest.getCoordinates();
  bool expectedComparsionValue = true;
  if(expectedCoordinates.size() != actualCoordinates.size()) {
    expectedComparsionValue = false;
  }
  else {
    for(int i = 0 ; i < expectedCoordinates.size() ; ++i) {
      if(!(expectedCoordinates.at(i).get() == actualCoordinates.at(i).get())) {
        expectedComparsionValue = false;
        break;
      }
    }
  }
  EXPECT_TRUE(expectedComparsionValue);
}

TEST_F(ShipTest, checkIfShipIsDestroyedProperlyTest)
{
  std::vector<int> coordinateXYFirst{1,2};
  std::vector<int> coordinateXYSecond{1,3};
  Coordinates2d cordinatesToHitFirst{coordinateXYFirst};
  Coordinates2d cordinatesToHitSecond{coordinateXYSecond};
  mShipToTest.hit(cordinatesToHitFirst);
  mShipToTest.hit(cordinatesToHitSecond);
  bool expectedShipStatus = false;
  bool actualShipStatus = mShipToTest.getStatus();
  EXPECT_EQ(expectedShipStatus, actualShipStatus);
}
