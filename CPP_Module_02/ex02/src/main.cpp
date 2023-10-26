#include <iostream>
#include "../inc/Fixed.hpp"

// int	main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
	
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0; 
// }

int main(void)
{
	Fixed a;
	Fixed const sumc(Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed sum(Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed const sub(Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed const mulc(Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed mul(Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const div(Fixed( 5.05f ) / Fixed( 2 ) );

	// Fixed ();

	// Fixed sum();

	// Fixed sum();

	// Fixed sum();
	std::cout << "---" << "The 4 increment/decrement operators" << "----" << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;
	std::cout << "++a\t\t\t" << ++a << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;
	std::cout << "a++\t\t\t" << a++ << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;

	std::cout << "--------" << "OPERATORS" << "----------------" << std::endl;
	std::cout << "sum(+)\t\t\t" << sum << std::endl;
	std::cout << "sum const(+)\t\t" << sumc << std::endl;
	
	std::cout << "sub(-)\t\t\t" << sub << std::endl;
	std::cout << "mu(*)\t\t\t" << mul << std::endl;
	std::cout << "mul const(*)\t\t" << mulc << std::endl;
	std::cout << "div(/)\t\t\t" << div << std::endl;

	std::cout << "--------" << "MIN MAX" << "----------------" << std::endl;
	std::cout << "min \t\t\t" << Fixed::min( sum, mul ) << std::endl;
	std::cout << "max\t\t\t" << Fixed::max( sum, mul ) << std::endl;
	std::cout << "min const\t\t" << Fixed::min( sumc, mulc ) << std::endl;
	std::cout << "max const\t\t" << Fixed::max( sumc, mulc ) << std::endl;
}