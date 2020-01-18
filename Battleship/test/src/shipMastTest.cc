#include "ShipMast.h"
#include "gtest/gtest.h"
#include <iostream>

class ShipMastTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        std::cout << "SetUp" << std::endl;
    }
    
    virtual void TearDown() {
        std::cout << "TearDown" << std::endl;
    }
};

TEST_F(ShipMastTest, SubtractTwoNumbers)
{
    std::cout << "Test" << std::endl;
    EXPECT_EQ(1,1);
}
