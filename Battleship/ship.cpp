#include "ship.h"
#include <algorithm>

bool Ship::isSunk()
{
    return std::all_of(mStatus.begin(), mStatus.end(), [](bool elem) -> bool {elem == false;});
}

std::vector<bool> Ship::getStatus()
{
    return mStatus;
}

std::pair<int, int> Ship::getCoordinates()
{
    return mCoordinates;
}

int Ship::getLength()
{
    return mLength;
}

bool Ship::isHorizontal()
{
    return mHorizontal;
}


bool Ship::computeHit(std::pair<int, int> cord)
{
    int x = mCoordinates.first;
    int y = mCoordinates.second;

    for(int i = 0; i < mLength; i++)
    {
        //check if hit
        if(x == cord.first && y == cord.second)
        {
            if(mStatus.at(i) == false)
            {
                return false;
            }    
            else
            {
                mStatus.at(i) = false;
                return true;
            }
        }


        if(mHorizontal) x++;
        else y++;
    }
}


