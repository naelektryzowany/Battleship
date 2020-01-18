#include "TerminalBoard.h"
#include <algorithm>
#include <iostream>

TerminalBoard::TerminalBoard(std::vector<std::vector<Coordinates2d>> shipCoordinates, int width, int height, char shipRepresentation, char boardRepresentation, char hitRepresentation) :
    mShipRepresentation(shipRepresentation), mBoardRepresentation(boardRepresentation), mHitRepresentation(hitRepresentation) {
        std::vector<char> widthVector(width, mBoardRepresentation);
        mBoard = std::vector<std::vector<char>>(height, widthVector);
        for(const auto &ship : shipCoordinates) {
            for(const auto &mastCoordinate : ship) {
                drawOnSurface(mastCoordinate, shipRepresentation);
            }
        }
    }
void TerminalBoard::draw() const {
    std::system("clear");
    for(const auto &yAxis : mBoard) {
        for(const auto &xAxis : yAxis) {
            std::cout << xAxis << " ";
        }
        std::cout << std::endl;
    }
}

void TerminalBoard::updateSurface(const CoordinatesIf& coordinate) {
    drawOnSurface(coordinate, mHitRepresentation);
}

void TerminalBoard::printActualScore(GameData gameData) {
    std::cout << "=> Podusmowanie rundy : " << std::endl;
    std::cout << "Pozostało statków : " << gameData.getSipsLeft() << std::endl;
    std::cout << "Statki zniszczone : " << gameData.getShipsDown() << std::endl;
}

void TerminalBoard::printEndScore(GameData gameData) const {
    std::cout << "=> Podusmowanie gry : " << std::endl;
    std::cout << "Pozostało statków : " << gameData.getSipsLeft() << std::endl;
    std::cout << "Statki zniszczone : " << gameData.getShipsDown() << std::endl;
    std::cout << "Procent strzałów celnych : " << gameData.getRatio() * 100 << "%" << std::endl;
}

void TerminalBoard::drawOnSurface(const CoordinatesIf& coordinate, char pixelRepresentation) {
    int xAxis = coordinate.getCoordinates().front();
    int yAxis = coordinate.getCoordinates().back();
    mBoard.at(yAxis).at(xAxis) = pixelRepresentation;
}
