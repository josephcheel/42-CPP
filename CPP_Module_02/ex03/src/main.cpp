#include <iostream>
#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

int main(void)
{
	const Point a(0.2f, 2.59873f);
	const Point b(6, 0);
	const Point c(3, 4);
	
	const Point p(0, 2.6f);

	std::cout << "Point A"<< std::endl;
	std::cout << a << std::endl;
	std::cout << "Point B"<< std::endl;
	std::cout << b << std::endl;
	std::cout << "Point C"<< std::endl;
	std::cout << c << std::endl;
	
	std::cout << "Point P"<< std::endl;
	std::cout << p << std::endl;
	bool answer = bsp(a, b, c, p);
	std::cout << std::boolalpha << answer << std::endl; //to see if its true or false
	//std::cout  << answer << std::endl;
	return (0);
}