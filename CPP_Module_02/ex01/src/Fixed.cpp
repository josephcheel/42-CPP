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
	//std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_nbr);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed_nbr = raw;
}

Fixed::Fixed(const int fixed_nbr) 
{
	_fixed_nbr = (int)roundf((fixed_nbr * (1 << _nbr_fract_bits)));
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_nbr)
{
	this->_fixed_nbr = (int)roundf(float_nbr * (1 << this->_nbr_fract_bits));
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	return((float)this->_fixed_nbr / (float)(1 << this->_nbr_fract_bits));
}

int		Fixed::toInt( void ) const
{
	return((int)roundf(this->_fixed_nbr / (1 << this->_nbr_fract_bits)));
}



std::ostream & operator<<(std::ostream &ostream,  const Fixed &fixed_nbr)
{
	ostream << fixed_nbr.toFloat();
	return (ostream);
}
