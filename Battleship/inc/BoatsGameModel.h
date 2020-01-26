#ifndef BOATS_GAME_MODEL_IF
#define BOATS_GAME_MODEL_IF
#include "GameModelIf.h"
#include "Ship2d.h"
#include "ShipFactoryIf.h"
#include "CoordinatesFactoryIf.h"
#include <unordered_map>
#include <memory>

class BoatsGameModel : public GameModelIf {
   // Prywatne klasy zagnieżdżone - używane jako "funkcje" pomocnicze w kontenerze unordered_map
   // HashFunction - "funkcja" haszująca dla elementów CoordinatesIf
   // ComparsionOperator - "operator" porównania dla elementów typu CoordinatesIf
   struct HashFunction {
    // losowo wymyślony algorytm haszowania
    std::size_t operator()(std::shared_ptr<CoordinatesIf> element) const
    {
        using std::hash;
        auto elements = element->getCoordinates();
        auto val = 0xCAFE;
        int shift = 1;
        for(int elem : elements) {
            val ^= std::hash<int>()(elem) << (++shift);
        }
    return  val;
    }
   };
   struct ComparsionOperator {
    bool operator()(const std::shared_ptr<CoordinatesIf>& lhs, const std::shared_ptr<CoordinatesIf>& rhs) const
    {
        return *lhs == *rhs;
    }
   };

   public:
   BoatsGameModel(std::vector<std::vector<std::shared_ptr<CoordinatesIf>>> coordinates,  ShipFactoryIf *shipFactory, CoordinatesFactoryIf *coordinatesFactory);
   virtual GameData getEndGameData() const;
   virtual GameData getActualGameData() const;
   virtual bool computeHit(CoordinatesIf& coordinates);
   private:
   std::vector<std::unique_ptr<ShipIf>> mShips;
   // Znalezienie elementu występującego w kontenerze unordered_map jest realizowane w czasie stałym(złożoność oczekiwana)
   std::unordered_map<std::shared_ptr<CoordinatesIf>, int, HashFunction, ComparsionOperator> mShipCoordinates;
   std::unique_ptr<ShipFactoryIf>  mShipFactory;
   std::unique_ptr<CoordinatesFactoryIf>  mCoordinatesFactory;
   int mHits = 0;
   int mMiss = 0;
   int mInitialShipCount = 0;
   int mShipsDown = 0;

};

#endif
