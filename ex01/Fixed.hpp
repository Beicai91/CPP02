#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed
{
    private:
        int _value;
        static const int    _fracBits;
    
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed(const int num);
        Fixed(const float num);
        Fixed& operator=(const Fixed &other);
        ~Fixed();
        int getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fpNum);

#endif