#ifndef SCALAVAR_CONVERTER_HPP
# define SCALAVAR_CONVERTER_HPP

# include <iostream>
# include <limits>
# include <sstream>
# include <iomanip>
# include <cmath>
# include <cstdlib>

class ScalarConverter
{
	public:
		static  void	convert(std::string str);
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter(std::string str);

		~ScalarConverter(void);
		ScalarConverter &	operator=(ScalarConverter const & rhs);

		static char	convertChar(std::string str);
		static int		convertInt(std::string str);
		static float	convertFloat(std::string str);
		static double	convertDouble(std::string str);
		std::string			_str;
};

#endif