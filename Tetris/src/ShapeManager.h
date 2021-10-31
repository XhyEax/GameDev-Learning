/*
 * @Author: Xhy
 * @Date: -20-2-110-3-1 -17:48:07
 * @LastEditTime: 2021-11-01 01:56:23
 * @Description: shape
 */
#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include "Point.h"
using namespace std;

class ShapeManager
{
public:
    // I,L,J,T,O,S,Z 7种形态
    int shapeIndex = 0;
    // 4个方向
    int stateIndex = 0;
    // x y偏移数组
    vector<Point> shapes[7][4] = {{{{0, 0}, {0, 1}, {0, 2}, {0, -1}}, {{0, 0}, {-1, 0}, {-2, 0}, {1, 0}}, {{0, 0}, {0, 1}, {0, 2}, {0, -1}}, {{0, 0}, {-1, 0}, {-2, 0}, {1, 0}}},

                                  {{{0, 0}, {0, 1}, {0, 2}, {-1, 0}}, {{0, 0}, {-1, 0}, {-2, 0}, {0, -1}}, {{0, 0}, {1, 0}, {0, -1}, {0, -2}}, {{0, 0}, {0, 1}, {1, 0}, {2, 0}}},

                                  {{{0, 0}, {0, 1}, {0, 2}, {1, 0}}, {{0, 0}, {0, 1}, {-1, 0}, {-2, 0}}, {{0, 0}, {-1, 0}, {0, -1}, {0, -2}}, {{0, 0}, {1, 0}, {2, 0}, {0, -1}}},

                                  {{{0, 0}, {-1, 0}, {0, -1}, {1, 0}}, {{0, 0}, {0, 1}, {0, -1}, {1, 0}}, {{0, 0}, {0, 1}, {-1, 0}, {1, 0}}, {{0, 0}, {0, 1}, {-1, 0}, {0, -1}}},

                                  {{{0, 0}, {0, 1}, {-1, 1}, {-1, 0}}, {{0, 0}, {0, 1}, {-1, 1}, {-1, 0}}, {{0, 0}, {0, 1}, {-1, 1}, {-1, 0}}, {{0, 0}, {0, 1}, {-1, 1}, {-1, 0}}},

                                  {{{0, 0}, {0, 1}, {-1, 1}, {1, 0}}, {{0, 0}, {1, 0}, {1, 1}, {0, -1}}, {{0, 0}, {0, 1}, {-1, 1}, {1, 0}}, {{0, 0}, {1, 0}, {1, 1}, {0, -1}}},

                                  {{{0, 0}, {0, 1}, {-1, 0}, {1, 1}}, {{0, 0}, {0, 1}, {1, -1}, {1, 0}}, {{0, 0}, {0, 1}, {-1, 0}, {1, 1}}, {{0, 0}, {0, 1}, {1, -1}, {1, 0}}}};

    vector<Point> shape;
    set<Point> points;

    ShapeManager()
    {
        srand(time(NULL));
    }

    void rotateShape(int newStateIndex)
    {
        stateIndex = newStateIndex;
        shape = shapes[shapeIndex][newStateIndex];
    }

    void getNewRandomShape()
    {
        shapeIndex = rand() % 7;
        stateIndex = rand() % 4;
        shape = shapes[shapeIndex][stateIndex];
    }

    void getPoints(int x, int y)
    {
        points.clear();
        for (int i = 0; i < 4; i++)
        {
            int shapeX = shape[i].x;
            int shapeY = shape[i].y;
            int px = x + shapeX;
            int py = y + shapeY;
            Point point = Point(px, py);
            points.insert(point);
        }
    }
};

#endif