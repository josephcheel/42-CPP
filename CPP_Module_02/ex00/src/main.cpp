#include <iostream>
#include "../inc/Fixed.hpp"

int	main( void ) {

	// Default Constructor
	Fixed a;
	// Copy Constructor
	Fixed b(a);
	Fixed c;
	
	// Copy Assignment Operator
	c = b;

	// getRawBits getter
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	// Setter RawBits
	a.setRawBits(20);
	std::cout << a.getRawBits() << std::endl;
	
	return 0;
}
