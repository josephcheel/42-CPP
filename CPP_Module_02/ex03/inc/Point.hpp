#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"

class Point {

	private:
		Fixed _x;
		Fixed _y;
	public:
		Point();
		Point(float const x, float const y);
		Point(const Point &copy);
		Point const &operator=( Point const &copy);
		~Point();
		float getPointY(void) const;
		float getPointX(void) const;
};

std::ostream	& operator<<(std::ostream &ostream,  const Point &points); 
bool bsp( Point const a, Point const b, Point const c, Point const point);
float	get_triangle_area(Point const a, Point const b, Point const c);

#endif