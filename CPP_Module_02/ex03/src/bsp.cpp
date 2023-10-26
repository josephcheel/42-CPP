#include "Point.hpp"
#include "../inc/Fixed.hpp"

float ft_abs(float x)
{
	if (x >= 0)
		return (x);
	else
		return (x * -1);
}

float	get_triangle_area(Point const a, Point const b, Point const c)
{
	float x1 = a.getPointX();
	float x2 = b.getPointX();
	float x3 = c.getPointX();
	float y1 = a.getPointY();
	float y2 = b.getPointY();
	float y3 = c.getPointY();
	
	float result = ft_abs(((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))) / 2);

	return(result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float Area;
	float A1;
	float A2;
	float A3;

	Area = get_triangle_area(a, b, c);
	A1 = get_triangle_area(a, b, point);
	A2 = get_triangle_area(b, c, point);
	A3 = get_triangle_area(a, point, c);

	// std::cout << "Area " << Area << std::endl;
	// std::cout << "A1 " << A1 << std::endl;
	// std::cout << "A2 " << A2 << std::endl;
	// std::cout << "A3 " << A3 << std::endl;
 	if (Area == (A1 + A2 + A3))
		return (true);
	else
		return(false);	
}
