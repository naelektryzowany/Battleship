# Battleship
Gra w statki, zaliczenie laboratorium - Tworzenie i utrzymanie czystego kodu
# Kompilacja projektu : 
g++ main.cc ShipMast.h ShipMast.cc  CoordinatesIf.h Coordinates2d.h Coordinates2d.cc ShipIf.h Ship2d.h Ship2d.cc GameData.h GameData.cc GameModelIf.h BoatsGameModel.h BoatsGameModel.cc  SurfaceIf.h TerminalBoard.h TerminalBoard.cc ShipFactoryIf.h Ship2dFactory.h Ship2dFactory.cc CoordinatesFactoryIf.h Coordinates2dFactory.h Coordinates2dFactory.cc GameControllerIf.h BoatsGame.h BoatsGame.cc GameStrategyIf.h TerminalBoats2d.h TerminalBoats2d.cc -o game -std=c++11

# Statyczna analiza kodu (wydać w katalogu w którym znajdują się pliki z kodem źródłowym) 
cppcheck --enable=all  .

# gtest (folder test) -> g++ -Wall -g -pthread gTest.cc shipMastTest.cc -o test  -lgtest_main  -lgtest -lpthread -I../
