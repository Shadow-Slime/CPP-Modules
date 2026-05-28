#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << fract_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)(roundf(value * (1 << fract_bits))); //same as multiplying by 2^fract_bits
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called"  << std::endl;
	if (this != &copy)
	{
		value = copy.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream& out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed& other) const
{
	return value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return value != other.value;
}

Fixed Fixed::operator+(const Fixed &copy) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() + copy.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &copy) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() - copy.getRawBits());
	return result;
}

//Fixed operator*(const Fixed &copy) const;

//Fixed operator/(const Fixed &copy) const;

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)value / (float)(1 << fract_bits));
}

int Fixed::toInt(void) const
{
	return ((int)this->toFloat());
}



