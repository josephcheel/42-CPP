#include <iostream>
#include "../inc/Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(Fixed( 5.05f ) * Fixed( 2 ));
	
	Fixed nbr1( 5.05f );
	Fixed nbr2( 2);

	Fixed const nbr1c( 5.054f );
	Fixed const nbr2c( 5.05f );


	std::cout << "--------" << "FIRST COMPARISON" << "----------------" << std::endl;
	std::cout << std::boolalpha << "a = " << a <<  "; b = " << b << ";" << std::endl;
	std::cout << "a > b " << (a > b) << std::endl;
	std::cout << "a < b " << (a < b) << std::endl;
	std::cout << "a >= b " << (a >= b)  << std::endl;
	std::cout << "a <= b " << (a <= b)  << std::endl;
	std::cout << "a != b " << (a != b)  << std::endl;
	
	std::cout << "--------" << "SECOND COMPARISON" << "----------------" << std::endl;
	a = 42.42f;
	std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
	std::cout << "a > b " << (a > b) << std::endl;
	std::cout << "a < b " << (a < b) << std::endl;
	std::cout << "a >= b " << (a >= b)  << std::endl;
	std::cout << "a <= b " << (a <= b)  << std::endl;
	std::cout << "a != b " << (a != b)  << std::noboolalpha << std::endl;

	std::cout << "---" << "The 2 inecrement operators" << "----" << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;
	std::cout << "++a\t\t\t" << ++a << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;
	std::cout << "a++\t\t\t" << a++ << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;
	
	std::cout << "---" << "The 2 decrement operators" << "----" << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;
	std::cout << "--a\t\t\t" << ++a << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;
	std::cout << "a--\t\t\t" << a++ << std::endl;
	std::cout << "a\t\t\t" << a << std::endl;

	
	std::cout << "--------" << "OPERATORS (nbr1 and nbr2)" << "----------------" << std::endl;
	std::cout << "nbr1 = " << nbr1 << "; nbr2 = " << (Fixed )nbr2 << ";" << std::endl;
	std::cout << "sum(+)\t\t\t" << (nbr1 + nbr2) << std::endl;
	std::cout << "sub(-)\t\t\t" << (nbr1 - nbr2) << std::endl;
	std::cout << "mul(*)\t\t\t" << (nbr1 * nbr2) << std::endl;
	std::cout << "div(/)\t\t\t" << (nbr1 / nbr2) << std::endl;

	std::cout << "--------" << "MIN MAX (nbr1 and nbr2)" << "----------------" << std::endl;
	std::cout << "Min and max functions return the min or max number respectively" << std::endl;
	std::cout << "min \t\t\t" << Fixed::min( nbr1, nbr2) << std::endl;
	std::cout << "max\t\t\t" << Fixed::max( nbr1, nbr2 ) << std::endl;
	std::cout << "min const\t\t" << Fixed::min( nbr1c, nbr2c ) << std::endl;
	std::cout << "max const\t\t" << Fixed::max( nbr1c, nbr2c ) << std::endl;
}
