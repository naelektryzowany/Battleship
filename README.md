# Battleship
Gra w statki, zaliczenie laboratorium - Tworzenie i utrzymanie czystego kodu

# Kompilacja -> wydać komendę cmake ../ w Katalogu build, następnie wydać komendę make (w katalogu build)

# Statyczna analiza kodu (wydać w katalogu w którym znajdują się pliki z kodem źródłowym) 
cppcheck --enable=all  src/ -I inc/

# Pokrycie kodu (robocze)
gcov TesMain.cc.gcno
lcov --capture --directory . --output-file main_coverage.info
genhtml main_coverage.infocd --output-directory out

# TODO : dodać konstruktory domyślne do klas które ich nie posiadają
