#ifndef GAME_DATA_H
#define GAME_DATA_H


class GameData {
    public:
    GameData(double ratio, int shipsLeft, int shipsDown) : mRatio(ratio), mShipsLeft(shipsLeft), mShipsDown(shipsDown) {}
    double getRatio() const;
    int getSipsLeft() const;
    int getShipsDown() const;
    private:
    double mRatio;
    int mShipsLeft;
    int mShipsDown;

};

#endif