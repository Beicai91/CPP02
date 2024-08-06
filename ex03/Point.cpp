#include "Point.hpp"

//constructor, destructor
Point::Point(): _x(Fixed(0)), _y(Fixed(0))
{}

Point::Point(const float num1, const float num2): _x(Fixed(num1)), _y(Fixed(num2))
{}

Point::Point(const Point &other): _x(other._x), _y(other._y)
{}

Point::~Point()
{}

//operator overload
Point   &Point::operator=(const Point &other)
{
    if (this == &other) // this is a pointer, == checks if they point to the same address
        return (*this);
    //copy other non-const member var
    return (*this);
}

//private member funcs
float   Point::_getRatio(const Point &a, const Point &b)
{
    float   ratio;

    //test
    std::cout << "point 1 x: " << a._x.toFloat() << "y: " << a._y.toFloat() << std::endl;
    std::cout << "point 2 x: " << b._x.toFloat() << "y: " << b._y.toFloat() << std::endl;
    //
    if (a._x == b._x)
        return (INFINITY);
    if (a._y == b._y)
        return (0.0);
    ratio = (a._y.toFloat() - b._y.toFloat()) / (a._x.toFloat() - b._x.toFloat());
    return (ratio);
}

//public member funcs
const Fixed &Point::getX() const
{
    return (this->_x);
}

const Fixed &Point::getY() const
{
    return (this->_y);
}

float   Point::py(const Point &p1, const Point &p2, const float px)
{
    //y = ratio*x + b
    float   py;
    float   ratio;
    float   b;

    ratio = _getRatio(p1, p2);
    if (ratio == 0)
        py = p1._x.toFloat();
    else if (ratio == INFINITY)
        py = INFINITY;     
    else
    {
        //test
        std::cout << "ratio " << ratio << std::endl;
        //
        b = p1._y.toFloat() - ratio * p1._x.toFloat();
        //test
        std::cout << "b " << b << std::endl;
        //
        py = ratio * px + b;
    }
    return (py);
}

const Point   **Point::sortPoints(const Point *points[], int len)
{
    const Point   *temp;

    for (int i = 0; i < len; ++i)
    {
        for (int j = i; j > 0; --j)
        {
            if ((*points[j])._x < (*points[j - 1])._x || ((*points[j])._x == (*points[j - 1])._x && (*points[j])._y < (*points[j - 1])._y))
            {
                //test
                std::cout << "swap" << std::endl;
                std::cout << "j " << j << std::endl;
                //
                temp = points[j];
                //test
                std::cout << "temp " << (*temp)._x << " " << (*temp)._y << std::endl;
                //
                points[j] = points[j - 1];
                points[j - 1] = temp;
            }
            else
                break;
        }
    }
    //test
    std::cout << "sorted points in sortTriPoints func" << std::endl;
    for (int i = 0; i < 3; ++i)
        std::cout << (*points[i]).getX().toFloat() << " " << std::endl;
    //
    return (points);
}