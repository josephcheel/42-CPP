#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x((float)x), _y((float)y)
{
	std::cout << "floating points constructor called" << std::endl;
}

Point::Point(const Point &copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

Point const &Point::operator=(Point const &copy)
{
	if (this != &copy)
	{
		_x = copy._x;
		_y = copy._y;
	}
	return (*this);
}

Point::~Point()
{
	std::cout << "Destructor called" <<  std::endl;
}

float	Point::getPointY(void) const
{
	return (this->_y.toFloat());
}
float	Point::getPointX(void) const
{
	return (this->_x.toFloat());
}

