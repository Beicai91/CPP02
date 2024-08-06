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
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        int getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

        static  Fixed   &min(Fixed &num1, Fixed &num2);
        static const Fixed  &min(const Fixed &num1, const Fixed &num2);
        static  Fixed   &max(Fixed &num1, Fixed &num2);
        static const Fixed   &max(const Fixed &num1, const Fixed &num2); 

        friend std::ostream &operator<<(std::ostream &os, const Fixed &fpNum);

        bool    operator<(const Fixed &other) const;
        bool    operator>(const Fixed &other) const;
        bool    operator<=(const Fixed &other) const;
        bool    operator>=(const Fixed &other) const;
        bool    operator==(const Fixed &other) const;
        bool    operator!=(const Fixed &other) const;

        Fixed   operator+(const Fixed &other) const;
        Fixed   operator-(const Fixed &other) const;
        Fixed   operator*(const Fixed &other) const;
        Fixed   operator/(const Fixed &other) const;
        
        Fixed   &operator++();
        Fixed   operator++(int);
        Fixed   &operator--();
        Fixed   operator--(int);
};

#endif