#include "ShipMast.h"
#include "gtest/gtest.h"
#include <iostream>

class ShipMastTest : public ::testing::Test {
  protected :
    std::vector<int> mXYCoordinate{1,2};
    Coordinates2d mCoordinatesForMast{mXYCoordinate};
    ShipMast mShipMastToTest{mCoordinatesForMast};
};

TEST_F(ShipMastTest, checkInitialStatusTest)
{
    bool expectedStatus = true;
    bool actualStatus = mShipMastToTest.getStatus();
    EXPECT_EQ(expectedStatus, actualStatus);
}

TEST_F(ShipMastTest, checkStatusAfterChangeTest)
{
    bool expectedStatus = false;
    mShipMastToTest.setStatus(expectedStatus);
    bool actualStatus = mShipMastToTest.getStatus();
    EXPECT_EQ(expectedStatus, actualStatus);
}

TEST_F(ShipMastTest, checkIfProperCoordinatesAreReturnedTest)
{
    std::vector<int> expectedXYCoordinates = {1,2};
    Coordinates2d expectedCoordinates(expectedXYCoordinates);
    Coordinates2d actualCoordinates = mShipMastToTest.getCoordinates();
    EXPECT_EQ(expectedCoordinates, actualCoordinates);
}
