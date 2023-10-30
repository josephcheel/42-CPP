#include <iostream>
#include "../inc/Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(2.4f);
	
	Fixed nbr1( 5.05f );
	Fixed nbr2( 2);

	Fixed const nbr1c( 5.05f );
	Fixed const nbr2c( 2);

	std::cout << "--------" << "COMPARISON" << "----------------" << std::endl;
	std::cout << "a > b " << (a > b) << std::endl;
	std::cout << "a < b " << (a < b) << std::endl;
	std::cout << "a >= b " << (a >= b)  << std::endl;
	std::cout << "a <= b " << (a <= b)  << std::endl;
	std::cout << "a != b " << (a != b)  << std::endl;

	std::cout << "---" << "The 4 increment/decrement operators" << "----" << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;
	std::cout << "++a\t\t\t" << ++a << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;
	std::cout << "a++\t\t\t" << a++ << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;

	std::cout << "--------" << "OPERATORS" << "----------------" << std::endl;
	std::cout << "sum(+)\t\t\t" << (nbr1 + nbr2) << std::endl;
	std::cout << "sub(-)\t\t\t" << (nbr1 - nbr2) << std::endl;
	std::cout << "mul(*)\t\t\t" << (nbr1 * nbr2) << std::endl;
	std::cout << "div(/)\t\t\t" << (nbr1 / nbr2) << std::endl;

	std::cout << "--------" << "MIN MAX" << "----------------" << std::endl;
	std::cout << "min \t\t\t" << Fixed::min( nbr1, nbr2) << std::endl;
	std::cout << "max\t\t\t" << Fixed::max( nbr1, nbr2 ) << std::endl;
	std::cout << "min const\t\t" << Fixed::min( nbr1c, nbr2c ) << std::endl;
	std::cout << "max const\t\t" << Fixed::max( nbr1c, nbr2c ) << std::endl;
}