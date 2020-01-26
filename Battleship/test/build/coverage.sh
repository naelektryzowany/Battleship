#!/bin/bash
eval "./game"
eval "lcov --capture --directory ./CMakeFiles/game.dir/home/lukasz/Dokumenty/Programowanie/Battleship/Battleship/src/ --output-file main_coverage.infocd"
eval "genhtml main_coverage.infocd --output-directory out"
eval "firefox ./out/index.html &"

