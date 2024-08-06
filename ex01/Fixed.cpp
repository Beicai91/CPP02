#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed()
{
    this->_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = num * (1 << _fracBits);
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = static_cast<int>(roundf(num * (1 << _fracBits)));
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    this->_value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return (this->_value);
}

void    Fixed::setRawBits(int raw)
{
    this->_value = raw;
}

float    Fixed::toFloat() const
{
    float   fNum;

    fNum = (static_cast<float>(this->_value)) / (1 << _fracBits);
    return (fNum);
}

int Fixed::toInt() const
{
    int num;

    num = this->_value / (1 << _fracBits);
    return (num);
}

std::ostream& operator<<(std::ostream &os, const Fixed &fpNum)
{
    os << fpNum.toFloat();
    return (os);
}