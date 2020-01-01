#include "TerminalBoats2d.h"
#include "Ship2dFactory.h"
#include "Coordinates2dFactory.h"
#include <iostream>
#include <algorithm>

void TerminalBoats2d::prepareToGame() {
    bool loopPredicate = true;
    std::string userInputEndKeyword = "end";
    mBoardSize = getBoardSize();
    std::vector<std::vector<Coordinates2d>> shipCoordinates = getShipCoordinares();
    mGame.reset(new BoatsGameModel(coordinates2dToGeneric(shipCoordinates), new Ship2dFactory(), new Coordinates2dFactory()));
    mBoard.reset(new TerminalBoard(shipCoordinates, mBoardSize.first, mBoardSize.second, '+', '#', 'o'));
}

void TerminalBoats2d::runGame() {
    std::cout << "\nGRA ROZPOCZĘTA\n" << std::endl;
    mBoard->draw();
    do {
        Coordinates2d coordinate = getHitCoordinates();
        mGame->computeHit(coordinate);
        mBoard->updateSurface(coordinate);
        mBoard->draw();
        mBoard->printActualScore(mGame->getActualGameData());
    } while(mGame->getActualGameData().getSipsLeft() > 0);
    mBoard->printEndScore(mGame->getEndGameData());
}

std::pair<int,int> TerminalBoats2d::getBoardSize() {
    int xAxis = readIntegerValue("Wprowadź rozmiar mapy(szerokość) : ");
    int yAxis = readIntegerValue("Wprowadź rozmiar mapy(wysokość) : ");
    return std::make_pair(xAxis,yAxis);
}

Coordinates2d TerminalBoats2d::getHitCoordinates() {
    bool loopPredicate = true;
    int xAxis = 0;
    int yAxis = 0;
    std::cout << "Wprowadź współrzędne strzału : " << std::endl;
    while(loopPredicate == true) {
        xAxis = readIntegerValue("Wprowadź współrzędną x (szerokość) : ");
        yAxis = readIntegerValue("Wprowadź współrzędną y (wysokość) : ");
        if(checkIfCoordinatesFitInBoard(Coordinates2d({xAxis,yAxis}))) {
            loopPredicate = false;
        }
        else {
            std::cout << "Niepoprawne współrzędne" << std::endl;
        }
    }
    return Coordinates2d({xAxis,yAxis});
}

std::vector<std::vector<Coordinates2d>> TerminalBoats2d::getShipCoordinares() {
    std::vector<std::vector<Coordinates2d>> shipCoordinates;
    std::vector<Coordinates2d> mastCoordinates;
    bool loopPredicate = true;
    bool isHorizontal = false;
    bool userDecision = false;
    while(loopPredicate == true) {
        userDecision = getDecisionFromUser("Czy chcesz dodać statek ?[T/N] : ");
        if(userDecision == false) {
            loopPredicate = false;
            continue;
        }
        isHorizontal = getDecisionFromUser("Układ Poziomy(N - oznacza pionowy) ?[T/N] : ");
        int mastNumber = readNumberOfMasts();
        mastCoordinates = readMastCoordinates(mastNumber, isHorizontal);
        if(checkIfAnyCollisionExists(mastCoordinates, shipCoordinates) == true) {
            std::cout << "Niestety nie można dodać statku, wystąpiła kolizja z innym statkiem" << std::endl;
        }
        else {
        shipCoordinates.push_back(mastCoordinates);
        }
        mastCoordinates.clear();
    }
    return shipCoordinates;
}

int TerminalBoats2d::readNumberOfMasts() {
    int input = 0;
    int maxNumberOfMasts = mBoardSize.first > mBoardSize.second ? mBoardSize.second : mBoardSize.first;
    std::string prompt = "Wprowadź ilość masztów dla statku (więcej niz 0 i mniej niż " + std::to_string(maxNumberOfMasts) + ") : ";
    do {
        input = readIntegerValue(prompt);
    } while(input > maxNumberOfMasts);
    return input;
}
std::vector<Coordinates2d> TerminalBoats2d::readMastCoordinates(int masts, bool isHorizontal) {
    std::vector<Coordinates2d> shipCoordinates;
    int xAxis = readIntegerValue("Podaj współrzędną x dla masztu(punkt zaczepienia) : ");
    int yAxis = readIntegerValue("Podaj współrzędną y dla masztu(punkt zaczepienia) : ");
    int iterations = 0;
    while(iterations < masts) {
        Coordinates2d coordinates({xAxis,yAxis});
        if(!checkIfCoordinatesFitInBoard(coordinates)) {
            std::cout << "Podane współrzędne nie umożliwiają postawienia statku składającego się z następującej liczby masztów : " << masts << std::endl;
            iterations = 0;
            xAxis = readIntegerValue("Podaj współrzędną x dla masztu(punkt zaczepienia) : ");
            yAxis = readIntegerValue("Podaj współrzędną y dla masztu(punkt zaczepienia) : ");
        }
        else {
            isHorizontal ? xAxis++ : yAxis++;
            ++iterations;
            shipCoordinates.push_back(coordinates);
        }
    }
    return shipCoordinates;
}

bool TerminalBoats2d::checkIfCoordinatesFitInBoard(Coordinates2d coordinates) {
    int xAxis = coordinates.getCoordinates().front();
    int yAxis = coordinates.getCoordinates().back();
    int coordinatesOk = false;
    if(xAxis >= 0 && yAxis >= 0 && xAxis <= mBoardSize.first && yAxis <= mBoardSize.second) {
        coordinatesOk = true;
    }
    return coordinatesOk;
}

int TerminalBoats2d::readIntegerValue(std::string prompt) {
    int input = 0;
    do {
        std::cout << prompt;
        std::cin >> input;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
        }
    } while(input < 0);
    return input;
}

void TerminalBoats2d::transformStringToCorrectFormat(std::string& stringToCorrect) {
    std::transform(stringToCorrect.begin(), stringToCorrect.end(), stringToCorrect.begin(),
        [](unsigned char c){ return std::tolower(c); });
}

bool TerminalBoats2d::checkIfAnyCollisionExists(std::vector<Coordinates2d> coordinateToCheck, std::vector<std::vector<Coordinates2d>> shipCoordinates) {
    bool collisionExist = false;
    for(const auto &shipCoordinate : shipCoordinates) {
        for(int i = 0 ; i < coordinateToCheck.size() ; ++i) {
            for(int j = 0 ; j < shipCoordinate.size() ; ++j) {
                if(shipCoordinate.at(j) == coordinateToCheck.at(i)) {
                    collisionExist = true;
                    break;
                }
            }
        }
        if(collisionExist) {
            break;
        }
    }
    return collisionExist;
}

bool TerminalBoats2d::getDecisionFromUser(std::string prompt) {
    bool loopPredicate = true;
    bool userDecision = false;
    std::string userInput;
    while(loopPredicate) {
        std::cout << prompt;
        std::cin >> userInput;
        transformStringToCorrectFormat(userInput);
        if(userInput == "n") {
            loopPredicate = false;
            continue;
        }
        else if(userInput == "t") {
            userDecision = true;
            loopPredicate = false;
            continue;
        }
    }
    return userDecision;
}

std::vector<std::vector<std::shared_ptr<CoordinatesIf>>> TerminalBoats2d::coordinates2dToGeneric(std::vector<std::vector<Coordinates2d>> coordinates) const {
    std::vector<std::vector<std::shared_ptr<CoordinatesIf>>> genericCoordinates;
    for(auto shipCoordinates : coordinates) {
        std::vector<std::shared_ptr<CoordinatesIf>> shipGenericCoordinates;
        for(auto genericCoordinate : shipCoordinates) {
            shipGenericCoordinates.push_back(std::make_shared<Coordinates2d>(genericCoordinate));
        }
        genericCoordinates.push_back(shipGenericCoordinates);
    }
    return genericCoordinates;
}