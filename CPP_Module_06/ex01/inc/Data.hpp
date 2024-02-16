#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>


class Data {

	public:
		char	c;
		int		i;
		float	f;
		double	d;
		Data();
		~Data();
		Data(Data const & src);
		Data &	operator=(Data const & copy);
};

#endif
