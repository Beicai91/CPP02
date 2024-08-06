#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point   a(0.0, 0.0);
    Point   b(4.0, 4.0);
    Point   c(3.0, 1.0);
    Point   point(3.5, 1.5);

    std::cout << bsp(a, b, c, point) << std::endl;
    return (0);
}