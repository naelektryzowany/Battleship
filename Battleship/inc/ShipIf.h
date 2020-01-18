#ifndef SHIPIF_H
#define SHIPIF_H
#include "CoordinatesIf.h"
#include <functional>

class ShipIf {
    public:
    virtual std::vector<std::reference_wrapper<const CoordinatesIf>> getCoordinates() const = 0;
    virtual bool getStatus() const = 0;
    virtual void hit(CoordinatesIf& coordinate) = 0;
};

#endif