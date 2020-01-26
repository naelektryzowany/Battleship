#ifndef COORDINATES_2_D_H
#define COORDINATES_2_D_H
#include "CoordinatesIf.h"


class Coordinates2d : public CoordinatesIf {
    public:
    explicit Coordinates2d(std::vector<int> coordinates) : mCoordinates(coordinates), mDimension(coordinates.size()) {};
    virtual std::vector<int> getCoordinates(void) const;
    virtual bool operator==(const CoordinatesIf &rhs) const;
    private :
    std::vector<int> mCoordinates;
    int mDimension;
};

#endif
