#pragma once
#include <vector>
#include <array>
#include "Patterns.h"

class GameOfLife {
public:
    GameOfLife(const Patterns &pattern);

    ~GameOfLife(){};

    void PopulateGrids(const std::vector<std::vector<bool> > &pattern);
    void ChangeState();
    void Update();
    unsigned int GetNumberAliveAdjacentTo(const int x, const int y);
    bool IsAlive(const unsigned int x, const unsigned int y);
    void SetNext(bool state, const unsigned int x, const unsigned int y);
    void PrintState();
    enum {DEAD, ALIVE};
    unsigned int mSizeX;
    unsigned int mSizeY;
    bool mSwitchVal = true;
    std::vector<std::vector<bool> > * mActiveGrid;
    std::vector<std::vector<bool> > * mInActiveGrid;

    std::vector<std::vector<bool> > grid1;
    std::vector<std::vector<bool> > grid2;
};