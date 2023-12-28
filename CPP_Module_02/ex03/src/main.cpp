#include <iostream>
#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

// https://planetcalc.com/8108/

int main(void)
{
	const Point A(0.2f, 2.5f);
	const Point B(6, 0);
	const Point C(3, 4);
	
	const Point point(0, 2.6f);

	bool answer = bsp(A, B, C, point);
	std::cout << std::boolalpha << answer << std::endl; //to see if its true or false
	//std::cout  << answer << std::endl;
	return (0);
}