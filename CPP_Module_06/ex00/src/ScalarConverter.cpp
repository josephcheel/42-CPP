#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _str("")
{
	std::cout << "ScalarConverter Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string str) : _str(str)
{
	std::cout << "ScalarConverter Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	std::cout << "ScalarConverter Copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const & copy)
{
	std::cout << "ScalarConverter Assignation operator called" << std::endl;
	if (this != &copy)
	{
		_str = copy._str;
	}
	return (*this);
}

bool	isInt(std::string str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < (int)str.length())
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	isFloat(std::string str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i] || (str[i] == 'f' && i == static_cast<int>(str.length() - 1)))
		return (true);
	return (false);
}

bool	isChar(std::string str)
{
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return (true);
	return (false);
}

void	ScalarConverter::convert(std::string str)
{
	 std::cout << std::endl << std::fixed << std::numeric_limits<double>::max() << std::endl << std::endl;
	// std::cout << std::endl << std::fixed << std::numeric_limits<float>::max() << std::endl << std::endl;
	// std::cout << std::endl << std::fixed << std::numeric_limits<float>::min() << std::endl << std::endl;

	//  double positive_infinity = std::numeric_limits<float>::infinity();
    // double negative_infinity = -std::numeric_limits<double>::infinity();

    // std::cout << "Positive Infinity: " << positive_infinity << std::endl;
    // std::cout << "Negative Infinity: " << negative_infinity << std::endl;

	if (str == "nan" || str == "nanf" || std::isnan(std::atof(str.c_str())))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	else if (str == "+inff" || str == "+inf" )
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	else if (str == "-inff" || str == "-inf" )
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	else if ((!isFloat(str) && !isChar(str)))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	char c = convertChar(str);
	int i = convertInt(str);
	float f = convertFloat(str);
	double d = convertDouble(str);

	if (c == 0)
		std::cout << "char:\t\tNon displayable" << std::endl;
	else
		std::cout << "char:\t\t" << c << std::endl;
	
	if (i == 0 && str.length() >= 10)
		std::cout << "int:\t\timpossible" << std::endl;
	else
	std::cout << "int:\t\t" << i << std::endl;
	
	if (f == 0 && str.length() > 46)
		std::cout << "float:\t\timpossible" << std::endl;
	else
		std::cout << "float:\t\t" << std::setprecision(1) << std::fixed << f <<  "f" << std::endl;

	if (d == 0 && str.length() > 309)
		std::cout << "double:\t\timpossible" << std::endl;
	else
		std::cout << "double:\t\t" << std::setprecision(1) << std::fixed << d << std::endl;
}

unsigned char	ScalarConverter::convertChar(std::string str)
{
	if (isChar(str))
		return (static_cast<char>(str[0]));
	if (str.length() >= 1  && str.length() <= 3 && isFloat(str) == true )
	{
		double tmp = std::atof(str.c_str());
		if (tmp > std::numeric_limits<unsigned char>::max())
			return (0);
		unsigned char c = static_cast<unsigned char>(tmp);
		if (std::isprint(c) != 0)
			return(c);
	}
	return (0);
}

int		ScalarConverter::convertInt(std::string str)
{
	if (isChar(str))
		return (static_cast<int>(str[0]));
	if (str.length() >= 1 && isFloat(str) == true)
	{
		double tmp = std::atof(str.c_str());

		if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
			return (0);
		else
			return(static_cast<int>(tmp));
	}
	else
		return (0);
}

float	ScalarConverter::convertFloat(std::string str)
{
	if (isChar(str))
		return (static_cast<float>(str[0]));
	if (str.length() >= 1  && isFloat(str) == true)
	{
		
		if (str[str.length() - 1] == 'f')
			str.erase(str.length() - 1, 1);
		float tmp = std::atof(str.c_str());
		
		if (tmp > std::numeric_limits<float>::max() || tmp < -std::numeric_limits<float>::max())
			return (0);
		return(static_cast<float>(tmp));
	}
	else
		return (0);
}

double	ScalarConverter::convertDouble(std::string str)
{
	if (isChar(str))
		return (static_cast<double>(str[0]));
	if (str.length() >= 1  && isFloat(str) == true)
	{
		if (str[str.length() - 1] == 'f')
			str.erase(str.length() - 1, 1);
		double tmp = std::atof(str.c_str());
		if (tmp > std::numeric_limits<double>::max() || tmp < -std::numeric_limits<double>::max())
			return (0);
		return(static_cast<double>(std::atof(str.c_str())));
	}
	else
		return (0);
}
