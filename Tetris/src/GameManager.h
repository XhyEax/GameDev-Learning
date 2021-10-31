/*
 * @Author: Xhy
 * @Date: 2021-10-31 17:50:26
 * @LastEditTime: 2021-11-01 01:55:37
 * @Description: game & screen output
 */
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <algorithm>
#include <vector>
#include "Point.h"
#include "ShapeManager.h"

using namespace std;

#define GRID_HEIGHT 10
#define GRID_WIDTH 10

class GameManager
{
private:
    ShapeManager shapeManager;

    vector<vector<bool>> grids;
    vector<bool> emptyLine;
    vector<int> fullIndex;
    int curX;
    int curY;
    int score;

public:
    GameManager()
    {
        emptyLine = vector<bool>(GRID_WIDTH, false);
        shapeManager = ShapeManager();
        newGame();
    }

    void newGame()
    {
        score = 0;
        resetCurXY();
        resetGrids();
        shapeManager.getNewRandomShape();
    }

    void printGrids()
    {
        printf("now score: %d\n", score);
        for (int i = 0; i < GRID_WIDTH + 2; i++)
        {
            printf("*");
        }
        printf("\n");

        shapeManager.getPoints(curX, curY);

        for (int x = 0; x < GRID_HEIGHT; x++)
        {
            printf("*");
            for (int y = 0; y < GRID_WIDTH; y++)
            {
                Point p = Point(x, y);
                if (grids[x][y] || shapeManager.points.find(p) != shapeManager.points.end())
                {
                    printf("■");
                }
                else
                {
                    printf("_");
                }
            }
            printf("*\n");
        }

        for (int i = 0; i < GRID_WIDTH + 2; i++)
        {
            printf("*");
        }
        printf("\n");
    }

    void resetCurXY()
    {
        curX = 0;
        curY = GRID_WIDTH / 2 - 1;
    }

    void resetGrids()
    {
        grids.clear();
        for (int i = 0; i < GRID_HEIGHT; i++)
        {
            grids.push_back(emptyLine);
        }
    }

    void gameOver()
    {
        printf("game over! score: %d\nnew game start\n", score);
        newGame();
    }

    int getBottomGaps()
    {
        int bottom = GRID_HEIGHT;
        for (Point p : shapeManager.points)
        {
            int tmp = 0;
            int scanIndex = p.x + 1;
            if (scanIndex < 0)
                scanIndex = 0;
            for (int i = scanIndex; i < GRID_HEIGHT; i++)
            {
                if (grids[i][p.y])
                    break;
                tmp += 1;
            }
            bottom = min(tmp, bottom);
        }
        return bottom;
    }

    void checkGameOverOrNewShape()
    {
        resetCurXY();
        shapeManager.getNewRandomShape();
        shapeManager.getPoints(curX, curY);
        if (getBottomGaps() == 0)
        {
            printGrids();
            gameOver();
        }
    }

    void saveShapeToGrids()
    {
        for (Point p : shapeManager.points)
        {
            grids[p.x][p.y] = true;
        }
    }

    bool isValidMovement()
    {
        shapeManager.getPoints(curX, curY);
        int validCount = 0;
        for (Point p : shapeManager.points)
        {
            bool isXValid = p.x <= GRID_WIDTH - 1;
            bool isYValid = p.y >= 0 && p.y <= GRID_HEIGHT - 1;
            if (isXValid && isYValid)
                validCount += p.x < 0 || (!grids[p.x][p.y]) ? 1 : 0;
        }
        return validCount == 4;
    }

    void updateLines()
    {
        int gaps = getBottomGaps();
        bool BottomTouched = (gaps == 0);
        if (BottomTouched)
        {
            saveShapeToGrids();
            checkGameOverOrNewShape();
        }

        // check full line
        for (int i = 0; i < GRID_HEIGHT; i++)
        {
            bool tmp = true;
            for (int j = 0; j < GRID_WIDTH; j++)
            {
                tmp &= grids[i][j];
            }
            if (tmp)
            {
                fullIndex.push_back(i);
            }
        }

        // clear full line
        for (int i : fullIndex)
        {
            score++;
            grids.erase(grids.begin() + i);
            grids.insert(grids.begin(), emptyLine);
        }
    }

    void left()
    {
        curY -= 1;
        bool isValid = isValidMovement();
        if (!isValid)
        {
            //revert
            curY += 1;
            shapeManager.getPoints(curX, curY);
        }
    }

    void right()
    {
        curY += 1;
        bool isValid = isValidMovement();
        if (!isValid)
        {
            curY -= 1;
            shapeManager.getPoints(curX, curY);
        }
    }

    void down()
    {
        curX += 1;
        bool isValid = isValidMovement();

        if (isValid)
        {
            updateLines();
        }
        else
        {
            curX -= 1;
            shapeManager.getPoints(curX, curY);
        }
    }

    void drop()
    {
        int gaps = getBottomGaps();
        for (int i = 0; i < gaps; i++)
            down();
    }

    void rotate()
    {
        int stateIndexBak = shapeManager.stateIndex;
        int newStateIndex = stateIndexBak;
        if (stateIndexBak >= 3)
        {
            newStateIndex = 0;
        }
        else
        {
            newStateIndex += 1;
        }
        shapeManager.rotateShape(newStateIndex);

        bool isValid = isValidMovement();
        if (!isValid)
        {
            // revert
            shapeManager.rotateShape(stateIndexBak);
        }
    }
};
#endif