#ifndef SCALAVAR_CONVERTER_HPP
# define SCALAVAR_CONVERTER_HPP

# include <iostream>
# include <limits>
# include <sstream>

class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter(std::string str);

		~ScalarConverter(void);
		ScalarConverter &	operator=(ScalarConverter const & rhs);

		void	convert(std::string const & str);

	private:
		char	convertChar(std::string str);
		int		convertInt(std::string str);
		float	convertFloat(std::string str);
		double	convertDouble(std::string str);

		std::string			_str;
};

#endif