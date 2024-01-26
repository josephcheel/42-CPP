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

void	ScalarConverter::convert(std::string const & str)
{
	char c = convertChar(str);
	int i = convertInt(str);
	float f = convertFloat(str);
	double d = convertDouble(str);

	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}

	if (c == 0)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	
	if (i == 0 && str.length() >= 1 && std::stod(str) != 0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	
	// std::cout << "CONVERTED F"<< f << std::endl;
	// std::cout << "CONVERTED STOD" << std::stod(str) << std::endl;
	if (f == 0 && str.length() >= 1 && std::stod(str) != 0)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << f <<  "f" << std::endl;

	if (d == 0 && str.length() >= 1 && std::stod(str) != 0)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << d << std::endl;
	// std::cout << "int: " << this->convertInt(str) << std::endl;
	// std::cout << "float: " << this->convertFloat(str) << std::endl;
	// std::cout << "double: " << this->convertDouble(str) << std::endl;
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
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i])
		return (true);
	if (str[i] == 'f')
		return (true);
	return (false);
}

bool	isDouble(std::string str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i])
		return (true);
	return (false);
}

char	ScalarConverter::convertChar(std::string str)
{

	if (str.length() >= 1)
	{
		double tmp = std::stod(str);
		if (std::isprint(tmp) != 0)
			return((char)tmp);
	}
	return (0);
}

int		ScalarConverter::convertInt(std::string str)
{
	if (str.length() >= 1 && isInt(str) == true)
	{
		double tmp = std::stod(str);

		if (tmp >= std::numeric_limits<int>::max() || tmp <= std::numeric_limits<int>::min())
			return (0);
		else
			return(()std::stoi(str));
	}
	else
		return (0);
}

float	ScalarConverter::convertFloat(std::string str)
{
	if (str.length() >= 1 && isFloat(str) == true)
	{
		float tmp = std::stof(str);
		if (tmp >= std::numeric_limits<float>::max() || tmp <= std::numeric_limits<float>::min())
			return (0);
		return(std::stof(str));
	}
	else
		return (0);
}

double	ScalarConverter::convertDouble(std::string str)
{
	if (str.length() >= 1 && isDouble(str) == true)
	{
		return(std::stod(str));
	}
	else
		return (0);
}