/*
 * @Author: Xhy
 * @Date: 2021-09-11 11:27:43
 * @LastEditTime: 2021-09-11 16:29:15
 * @Description: 
 */
#include <iostream>
using namespace std;

const int HEIGHT = 10;
const int WIDTH = 10;

int graph[HEIGHT][WIDTH];

void print_graph()
{
    for (int i = 0; i < WIDTH + 2; i++)
    {
        printf("*");
    }
    printf("\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        printf("*");
        for (int j = 0; j < WIDTH; j++)
        {
            if (graph[i][j])
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

    for (int i = 0; i < WIDTH + 2; i++)
    {
        printf("*");
    }
    printf("\n");
}

int main()
{
    graph[2][3] = 1;
    graph[2][2] = 1;
    graph[3][2] = 1;
    print_graph();
    return 0;
}