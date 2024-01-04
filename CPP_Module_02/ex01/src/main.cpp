#include "../inc/Fixed.hpp"
#include <iostream>

int	main( void )
{
	Fixed a;
	// Int Constructor
	Fixed const b( 10 );
	// Float Constructor
	Fixed const c( 42.42f );
	// Copy Constructor
	Fixed const d( b );
	// Copy Assignment Operator 
	a = Fixed( 1234.4321f );

	// "<<" Operator
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	// ToInt() member function
	std::cout << "---------ToInt() Member Function--------" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	// ToFloat() member function
	std::cout << "---------ToFloat() Member Functionº--------" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	return 0;
}
