#include "../inc/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixed_nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" <<  std::endl;
}
Fixed &Fixed::operator=(const Fixed &copy)
{

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_fixed_nbr = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_nbr);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_nbr = raw;
}
