#include <iostream>
#include "../inc/Fixed.hpp"

int	main( void ) {

	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	// a.setRawBits(20);
	// std::cout << a.getRawBits() << std::endl;
	
	return 0;
}