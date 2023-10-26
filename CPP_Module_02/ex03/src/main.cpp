#include <iostream>
#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

int main(void)
{
	const Point a(0, 0);
	const Point b(6, 0);
	const Point c(3, 4);
	const Point p(7, 2);

	bool answer = bsp(a, b, c, p);
	//std::cout << std::boolalpha << answer << std::endl; //to see if its true or false
	std::cout  << answer << std::endl;
	return (0);
}