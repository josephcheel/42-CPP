#include "../inc/max.hpp"
#include "../inc/min.hpp"
#include "../inc/swap.hpp"
#include <iostream>
#include <string>

int	main( void )
{
	std::cout << "------------------INT----------------------" << std::endl << std::endl;
	
	int a = 2;
	int b = 3;
	
	::swap( a, b );
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::cout << std::endl << "------------------STD::STRING----------------------" << std::endl << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl ;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}