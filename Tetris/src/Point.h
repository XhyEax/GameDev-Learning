/*
 * @Author: Xhy
 * @Date: 2021-10-31 23:47:55
 * @LastEditTime: 2021-11-01 00:41:31
 * @Description: point
 */
#ifndef POINT_H
#define POINT_H
class Point
{
public:
    int x;
    int y;
    
    // for set
    bool operator<(const Point &target) const
    {
        if ((this->x < target.x) || (this->x == target.x && this->y < target.y))
            return true;
        else
            return false;
    }

    Point(int x, int y) : x(x), y(y){};
};

#endif