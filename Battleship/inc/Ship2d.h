#ifndef SHIP_2_d_H
#define SHIP_2_f_H
#include "ShipIf.h"
#include "ShipMast.h"

class Ship2d : public ShipIf {
    public:
    explicit Ship2d(std::vector<Coordinates2d> coordinates);
    virtual std::vector<std::reference_wrapper<const CoordinatesIf>> getCoordinates() const;
    virtual bool getStatus() const;
    virtual void hit(CoordinatesIf& coordinate);
    private:
    bool computestatus() const;
    std::vector<ShipMast> mMasts;
    bool mStatus = true;
};

#endif
