#include "Fixed.hpp"
#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    if ((a.getX() == b.getX() && a.getX() == c.getX()) || (a.getY() == b.getY() && a.getY() == c.getY()))
    {
        std::cout << "Invalid triangle points" << std::endl;
        return (false);
    }
    float   py_range1;
    float   py_range2;
    const Point   *points[3] = {&a, &b, &c};
    const Point   **sortedPoints =  Point::sortPoints(points, 3);
    //test
    std::cout << "sorted points " << std::endl;
    for (int i = 0; i < 3; ++i)
        std::cout << (*sortedPoints[i]).getX().toFloat() << " " << std::endl;
    //

    const Point xmin = (*sortedPoints[0]);
    const Point xmax = (*sortedPoints[2]);
    const Point xmid = (*sortedPoints[1]);

    if (point.getX() <= xmin.getX() || point.getX() >= xmax.getX())
        return (false);
    py_range2 = Point::py(xmin, xmax, point.getX().toFloat());
    //test
    std::cout << "py_range2 " << py_range2 << std::endl;
    //
    if (point.getX() < xmid.getX())
        py_range1 = Point::py(xmin, xmid, point.getX().toFloat());
    else
        py_range1 = Point::py(xmid, xmax, point.getX().toFloat());
    //test
    std::cout << "py_range1 " << py_range1 << std::endl;
    //
    if (py_range1 < py_range2)
    {
        if (py_range1 < point.getY().toFloat() && py_range2 > point.getY().toFloat())
            return (true);
        else
            return (false);
    }
    else
    {
        if (py_range1 > point.getY().toFloat() && py_range2 < point.getY().toFloat())
            return (true);
        else
            return (false);
    }
}