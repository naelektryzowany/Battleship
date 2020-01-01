#ifndef COORDINATESIF_H
#define COORDINATESIF_H
#include "CoordinatesIf.h"
#include <vector>


class CoordinatesIf {
    public:
    virtual std::vector<int> getCoordinates(void) const = 0;
    virtual bool operator==(const CoordinatesIf &rhs) const = 0;
};

#endif