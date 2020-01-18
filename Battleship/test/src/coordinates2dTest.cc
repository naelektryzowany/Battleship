#include "Coordinates2d.h"
#include "gtest/gtest.h"
#include <iostream>

class Coordinates2dTest : public ::testing::Test {
  protected :
    std::vector<int> mXYCoordinate{1,2};
    Coordinates2d mCoordinatesForTest{mXYCoordinate};
};

TEST_F(Coordinates2dTest, checkEqualityTest)
{
    std::vector<int> XYCoordinate{1,2};
    Coordinates2d coordinates{XYCoordinate};
    EXPECT_TRUE(mCoordinatesForTest == coordinates);
}

TEST_F(Coordinates2dTest, checkNonEqualityTest)
{
    std::vector<int> XYCoordinate{3,2};
    Coordinates2d coordinates{XYCoordinate};
    EXPECT_FALSE(mCoordinatesForTest == coordinates);
}

TEST_F(Coordinates2dTest, checkIfProperCoordinatesAreReturnedTest)
{
    std::vector<int> expectedCoordinates{1,2};
    std::vector<int> actualCoordinates = mCoordinatesForTest.getCoordinates();
    EXPECT_EQ(expectedCoordinates, actualCoordinates);
}
