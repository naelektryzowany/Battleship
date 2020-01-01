#include "BoatsGameModel.h"
#include <utility>
#include <iostream>

BoatsGameModel::BoatsGameModel(std::vector<std::vector<std::shared_ptr<CoordinatesIf>>> coordinates, ShipFactoryIf *shipFactory, CoordinatesFactoryIf *coordinatesFactory) : 
    mShipFactory(shipFactory), mCoordinatesFactory(coordinatesFactory) {
        for(const auto shipCoordinates : coordinates) {
            mShips.push_back(mShipFactory->createNewShip(shipCoordinates));
            for(const auto &coordinate : shipCoordinates) {
                mShipCoordinates.insert(std::make_pair(coordinate ,mShips.size() - 1));
            }
        }
        mInitialShipCount = mShips.size();
    }

GameData BoatsGameModel::getEndGameData() const {
    double ratio = (mHits/(double)(mHits + mMiss));
    int shipsLeft = static_cast<int>(mShips.size() - mShipsDown);
    return GameData {ratio, shipsLeft, mShipsDown};
}

GameData BoatsGameModel::getActualGameData() const {
    return getEndGameData();
}

bool BoatsGameModel::computeHit(CoordinatesIf& coordinates) {
    bool wasHit = false;
    std::shared_ptr<CoordinatesIf> shipCordinate = mCoordinatesFactory->createNewCoordinates(coordinates.getCoordinates());
    auto position = mShipCoordinates.find(shipCordinate);
    if(position != mShipCoordinates.end()) {
        mShips.at(position->second)->hit(coordinates);
        wasHit = true;
        mShipCoordinates.erase(position);
        if(mShips.at(position->second)->getStatus() != true) {
            mShipsDown++;
        }
        mHits++;
    }
    else {
        mMiss++;
    }
    return wasHit;
}