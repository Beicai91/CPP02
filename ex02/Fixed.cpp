#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

//constructors
Fixed::Fixed()
{
    this->_value = 0;
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int num)
{
    //std::cout << "Int constructor called" << std::endl;
    this->_value = num * (1 << _fracBits);
}

Fixed::Fixed(const float num)
{
    //std::cout << "Float constructor called" << std::endl;
    this->_value = static_cast<int>(roundf(num * (1 << _fracBits)));
}

//destructor
Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

//other member functions
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

Fixed   &Fixed::min(Fixed &num1, Fixed &num2)
{
    return (num1._value < num2._value) ? num1 : num2;
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
    return (num1._value < num2._value) ? num1 : num2;
}

Fixed   &Fixed::max(Fixed &num1, Fixed &num2)
{
    return (num1._value > num2._value) ? num1 : num2;
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
    return (num1._value > num2._value) ? num1 : num2;
}

//operator implementation 
Fixed   &Fixed::operator=(const Fixed &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    this->_value = other.getRawBits();
    return (*this);
}

std::ostream    &operator<<(std::ostream &os, const Fixed &fpNum)
{
    os << fpNum.toFloat();
    return (os);
}

bool    Fixed::operator<(const Fixed &other) const
{
    return (this->_value < other.getRawBits());
}

bool    Fixed::operator>(const Fixed &other) const
{
    return (this->_value > other.getRawBits());
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return (this->_value <= other.getRawBits());
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return (this->_value >= other.getRawBits());
}

bool    Fixed::operator==(const Fixed &other) const
{
    return (this->_value == other.getRawBits());
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return (this->_value != other.getRawBits());
}

Fixed  Fixed::operator+(const Fixed &other) const
{
    Fixed   res;
    
    res.setRawBits((this->toFloat() + other.toFloat()) * (1 << this->_fracBits));
    return (res);
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    Fixed   res;

    res.setRawBits((this->toFloat() - other.toFloat()) * (1 << this->_fracBits));
    return (res);
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    Fixed   res;

    res.setRawBits(this->toFloat() * other.toFloat() * (1 << this->_fracBits));
    return (res);
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    Fixed   res;

    res.setRawBits(this->toFloat() / other.toFloat() * (1 << this->_fracBits));
    return (res);
}

Fixed   &Fixed::operator++()
{
    (this->_value)++;
    return (*this);
}

Fixed  Fixed::operator++(int)
{
    Fixed   original;

    original = *this;
    (this->_value)++;
    return (original);
}

Fixed   &Fixed::operator--()
{
    (this->_value)--;
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed   original;

    original = *this;
    (this->_value)--;
    return (original);
}