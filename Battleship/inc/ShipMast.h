#ifndef SHIPMAST_H
#define SHIPMAST_H
#include "Coordinates2d.h"


class ShipMast {
    public:
    ShipMast(Coordinates2d coordinates) : mCoordinates(coordinates) {}
    virtual const Coordinates2d& getCoordinates() const;
    virtual void setStatus(bool newStatus);
    virtual bool getStatus() const;

    private:
    Coordinates2d mCoordinates;
    bool mIsOperational = true;
};

#endif