# README.md
This project is for Linux / Unix-like systems only.Windows is not supported.

This project uses SFML 2.6.2(included in the folder named SFML_2_6_2).
if you cannot compile,please link to the appropriate library files inside the SFML_2_6_2 directory.

---

## Compile with GCC
g++ main.cpp -o gomoku_game -I[your SFML/include path] -L[your SFML/lib path] -lsfml-graphics -lsfml-window -lsfml-system

## Compile with Clang
clang++ main.cpp -o gomoku_game -I[your SFML/include path] -L[your SFML/lib path] -lsfml-graphics -lsfml-window -lsfml-system

## Run
./gomoku_game
