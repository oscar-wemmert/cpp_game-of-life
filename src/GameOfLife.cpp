#include "GameOfLife.h"
#include <iostream>
#include "Patterns.h"

using std::vector; using std::cout; using std::endl;

GameOfLife::GameOfLife(const Patterns &pattern) {
    mSizeX = pattern.sizeX;
    mSizeY = pattern.sizeY;
    PopulateGrids(pattern.GetPattern());
    mActiveGrid = &grid1;
    mInActiveGrid = &grid2;
}

void GameOfLife::PopulateGrids(const vector<vector<bool> > &pattern) {
    for (int y = 0; y < mSizeY; ++y) {
        for (int x = 0; x < mSizeX; ++x) {
            grid1.resize(mSizeY, vector<bool>(mSizeX));
            grid2.resize(mSizeY, vector<bool>(mSizeX, 0));

            grid1[x][y] = pattern.at(y).at(x);
        }
    }
}

void GameOfLife::Update() {
    int nAlive;
    for (int y = 0; y < mSizeY; ++y) {
        for (int x = 0; x < mSizeX; ++x) {
            nAlive = GetNumberAliveAdjacentTo(x, y);
            if (IsAlive(x,y)) {
                if (nAlive < 2) SetNext(DEAD, x, y);
                else if (nAlive > 3) SetNext(DEAD, x, y);
                else SetNext(ALIVE, x, y);

            } else {
                if (nAlive == 3) SetNext(ALIVE, x, y);
                else SetNext(DEAD, x, y);
            }
        }
    }
    ChangeState();
}

void GameOfLife::SetNext(bool state, const unsigned int x, const unsigned int y) {
    mInActiveGrid->at(y).at(x) = state;
}

bool GameOfLife::IsAlive(const unsigned int x, const unsigned int y) { //readability
    return mActiveGrid->at(y).at(x);
}

unsigned int GameOfLife::GetNumberAliveAdjacentTo(const int x, const int y) {
    unsigned int result = 0;
    for (int tmpY = y-1; tmpY <= y+1; ++tmpY) { // for each Y in y-1, y, y+1
        for (int tmpX = x-1; tmpX <= x+1; ++tmpX) { // for each X in x-1, x, x+1
            if (tmpX == x && tmpY == y) continue;
            if (tmpY >= 0 && tmpY < mSizeY) { // range checks
                if (tmpX >= 0 && tmpX < mSizeX) { // range checks
                    if (mActiveGrid->at(tmpY).at(tmpX)) result+=1;
                }
            }
        }
    }
    return result;
}

void GameOfLife::ChangeState() {
    if (mSwitchVal) {
        mActiveGrid = &grid2;
        mInActiveGrid = &grid1;
    } else {
        mActiveGrid = &grid1;
        mInActiveGrid = &grid2;
    }
    mSwitchVal = !mSwitchVal;
}

void GameOfLife::PrintState() {
    for (int y = 0; y < mSizeY; ++y) {
        for (int x = 0; x < mSizeX; ++x) {
            if (mActiveGrid->at(y).at(x)) {
                cout << mActiveGrid->at(y).at(x);
            }
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl << endl << endl; 
}