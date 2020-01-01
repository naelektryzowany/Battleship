#ifndef GAME_MODEL_IF
#define GAME_MODEL_IF
#include "GameData.h"
#include "CoordinatesIf.h"

class GameModelIf {
   public:
   virtual GameData getEndGameData() const = 0;
   virtual GameData getActualGameData() const = 0;
   virtual bool computeHit(CoordinatesIf& coordinate) = 0;
};

#endif
