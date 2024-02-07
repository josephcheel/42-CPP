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

void	ScalarConverter::convert(std::string const & str)
{
	// std::cout << std::boolalpha << isFloat(str) << std::endl;
	if (str == "nan" || str == "nanf" || (!isFloat(str) && !isChar(str)))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
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
	
	if (f == 0 && str.length() > 1)
		std::cout << "float:\t\timpossible" << std::endl;
	else
	std::cout << "float:\t\t" << std::setprecision(1) << std::fixed << f <<  "f" << std::endl;

	std::cout << "double:\t\t" << std::setprecision(1) << std::fixed << d << std::endl;
}

unsigned char	ScalarConverter::convertChar(std::string str)
{
	if (isChar(str))
		return (static_cast<char>(str[0]));
	if (str.length() >= 1 && isFloat(str) == true)
	{
		double tmp = std::stod(str);
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
		double tmp = std::stod(str);

		int out = static_cast<int>(tmp);
		if (tmp >= std::numeric_limits<int>::max() || tmp <= std::numeric_limits<int>::min())
			return (0);
		else
			return(out);
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
		float tmp = std::stod(str);
		
		std::istringstream iss(str);
		iss >> tmp;
		if (tmp >= std::numeric_limits<float>::max() || tmp <= -std::numeric_limits<float>::max())
		{
			return (0);
		}
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
		std::istringstream iss(str);
		double tmp;
		iss >> tmp;
		if (tmp >= std::numeric_limits<double>::max() || tmp <= -std::numeric_limits<double>::max())
			return (0);
		return(std::stod(str));
	}
	else
		return (0);
}
