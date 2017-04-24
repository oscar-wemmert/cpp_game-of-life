#include <chrono>
#include <thread>
#include "GameOfLife.h"
#include "Patterns.h"

void sleep(unsigned int x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

int main(int argc, char const *argv[]) {
    int pnr = 2;
    if (argc == 1) pnr = atoi(argv[0]);

    Patterns p = (Patterns(2));
    GameOfLife gol = GameOfLife(p);
    while (1) {
        gol.PrintState();
        sleep(500);
        gol.Update();
    }
    return 0;
}