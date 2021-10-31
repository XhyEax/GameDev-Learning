/*
 * @Author: Xhy
 * @Date: 2021-10-31 17:49:38
 * @LastEditTime: 2021-11-01 01:56:57
 * @Description: input
 */
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "GameManager.h"
#include <iostream>

using namespace std;

class InputManager
{
private:
    GameManager &gameManager;

public:
    InputManager(GameManager &gameManager) : gameManager(gameManager)
    {
    }

    void doCmd()
    {
        char cmd;
        printf("w a s d (e to drop, q to quit)\nenter cmd:\n");
        cin >> cmd;
        switch (cmd)
        {
        case 'W':
        case 'w':
            gameManager.rotate();
            break;
        case 'A':
        case 'a':
            gameManager.left();
            break;
        case 'S':
        case 's':
            gameManager.down();
            break;
        case 'D':
        case 'd':
            gameManager.right();
            break;
        case 'E':
        case 'e':
            gameManager.drop();
            break;
        case 'Q':
        case 'q':
            exit(0);
            break;
        default:
            printf("error cmd, retry plz\n");
            break;
        }
    }
};

#endif