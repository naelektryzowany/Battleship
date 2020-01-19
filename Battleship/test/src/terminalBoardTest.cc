#include "TerminalBoard.h"
#include "gtest/gtest.h"
#include <iostream>

class TerminalBoardTest : public ::testing::Test {
  protected :
    char mBoardRepresentation = '#';
    char mShipRepresentation = '+';
    char mHitRepresentation = 'o';
    int mWidth = 5;
    int mHeight = 5;
    std::vector<int> mCoordinateXYFirst{1,1};
    std::vector<int> mCoordinateXYSecond{1,2};
    Coordinates2d mCordinatesForMastFirst{mCoordinateXYFirst};
    Coordinates2d mCordinatesForMastSecond{mCoordinateXYSecond};
    std::vector<Coordinates2d> mShipCoordinates{mCoordinateXYFirst, mCoordinateXYSecond};
    std::vector<std::vector<Coordinates2d>> mShipsCoordinates{mShipCoordinates};
    TerminalBoard mBoard{mShipsCoordinates, mWidth, mHeight, mShipRepresentation, mBoardRepresentation, mHitRepresentation};
};


TEST_F(TerminalBoardTest, checkIfBoardIsDrawnProperlyTest)
{
  testing::internal::CaptureStdout();
  mBoard.draw();
  std::string actualOutputWithSystemEncoding = testing::internal::GetCapturedStdout();
  // Trzeba usunąć zakodowany znak który dodawany jest do ciągu po wykonaniu polecenia system("clear")
  std::string actualOutput = actualOutputWithSystemEncoding.substr(actualOutputWithSystemEncoding.find_first_of('#'));
  std::string expectedOutput = "# # # # # \n"
                               "# + # # # \n"
                               "# + # # # \n"
                               "# # # # # \n"
                               "# # # # # \n";
  EXPECT_EQ(expectedOutput, actualOutput);
}

TEST_F(TerminalBoardTest, checkIfBoardIsUpdatedProperlyTest)
{
  testing::internal::CaptureStdout();
  std::vector<int> coordinateXYToHit{1,2};
  Coordinates2d cordinateToHit{coordinateXYToHit};
  mBoard.updateSurface(cordinateToHit);
  mBoard.draw();
  std::string actualOutputWithSystemEncoding = testing::internal::GetCapturedStdout();
  // Trzeba usunąć zakodowany znak który dodawany jest do ciągu po wykonaniu polecenia system("clear")
  std::string actualOutput = actualOutputWithSystemEncoding.substr(actualOutputWithSystemEncoding.find_first_of('#'));
  std::string expectedOutput = "# # # # # \n"
                               "# + # # # \n"
                               "# o # # # \n"
                               "# # # # # \n"
                               "# # # # # \n";
  EXPECT_EQ(expectedOutput, actualOutput);
}

TEST_F(TerminalBoardTest, checkIfActualScoreIsPrintedProperlyTest)
{
  testing::internal::CaptureStdout();
  GameData gameData(1., 2, 3);
  mBoard.printActualScore(gameData);
  std::string actualOutput = testing::internal::GetCapturedStdout();
  std::string expectedOutput = "=> Podusmowanie rundy : \n"
                               "Pozostało statków : 2\n"
                               "Statki zniszczone : 3\n";
  EXPECT_EQ(expectedOutput, actualOutput);
}

TEST_F(TerminalBoardTest, checkIfEndScoreIsPrintedProperlyTest)
{
  testing::internal::CaptureStdout();
  GameData gameData(1., 2, 3);
  mBoard.printEndScore(gameData);
  std::string actualOutput = testing::internal::GetCapturedStdout();
  std::string expectedOutput = "=> Podusmowanie gry : \n"
                               "Pozostało statków : 2\n"
                               "Statki zniszczone : 3\n"
                               "Procent strzałów celnych : 100%\n";
  EXPECT_EQ(expectedOutput, actualOutput);
}
