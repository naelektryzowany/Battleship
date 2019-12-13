#ifndef STATEK_H_
#define STATEK_H_
#include <vector>
#include <utility>

class Ship
{
    public:
    Ship(std::pair<int,int> coordinates, unsigned int length, bool horizontal) : mCoordinates(coordinates), mLength(length), mHorizontal(horizontal), mStatus(length, true)
    {}
    ~Ship() {}
    bool isSunk();
    std::vector<bool> getStatus();
    std::pair<int, int> getCoordinates();
    int getLength();
    bool isHorizontal();
    bool computeHit(std::pair<int, int> cord);

    private:
    bool mHorizontal;
    int mLength;
    std::pair<int, int> mCoordinates;
    std::vector<bool> mStatus;

};




#endif
