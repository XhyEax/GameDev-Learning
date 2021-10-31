/*
 * @Author: Xhy
 * @Date: 2021-10-31 00:37:29
 * @LastEditTime: 2021-10-31 23:23:45
 * @Description: main
 */
#include <iostream>
#include <string>
#include <vector>
#include "GameManager.h"
#include "InputManager.h"

using namespace std;

int main()
{
    GameManager gameManager = GameManager();
    InputManager inputManager = InputManager(gameManager);
    while (true)
    {
        gameManager.printGrids();
        inputManager.doCmd();
    }
    return 0;
}