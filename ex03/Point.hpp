#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <vector>

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;

        static float   _getRatio(const Point &a, const Point &b);
    
    public:
        Point();
        Point(const float num1, const float num2);
        Point(const Point &other);
        Point   &operator=(const Point &other);
        ~Point();
        const Fixed &getX() const;
        const Fixed &getY() const;
        static const Point  **sortPoints(const Point *points[], int len);
        static float   py(const Point &p1, const Point &p2, const float px);
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);
#endif