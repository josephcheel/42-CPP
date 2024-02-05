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

bool	isallprint(std::string str)
{
	int			nbr;
	std::string ret;

	nbr = 0;
	for (int x = 0; x < static_cast<int>(str.length()); x++)
	{
		if (std::isalpha(static_cast<char>(str[x])))
			nbr++;
	}
	if (!nbr)
		return (false);
	return (true);
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
	if (!str[i] || (str[i] == 'f' && str[i -1] == 'f'))
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

void	ScalarConverter::convert(std::string const & str)
{
	char c = convertChar(str);
	int i = convertInt(str);
	float f = convertFloat(str);
	double d = convertDouble(str);

	if (str == "nan" || str == "nanf" || isallprint(str) || !isDouble(str))
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
	
	if (i == 0 && str.length() >= 1 && !isallprint(str) && std::stod(str) != 0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	
	if ((f == 0 && str.length() >= 1 &&  !isallprint(str) && std::stod(str) != 0))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << f <<  "f" << std::endl;

	if (d == 0 && str.length() >= 1 && !isallprint(str) && std::stod(str) != 0)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << d << std::endl;
}

unsigned char	ScalarConverter::convertChar(std::string str)
{

	if (str.length() >= 1 && !isallprint(str))
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
	if (str.length() >= 1 && !isallprint(str) && isFloat(str) == true )
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
	if (str.length() >= 1  && !isallprint(str) && isFloat(str) == true)
	{
		
		if (str[str.length() - 1] == 'f')
			str.erase(str.length() - 1, 1);
		float tmp = std::stof(str);
		
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
	if (str.length() >= 1  && !isallprint(str) && isFloat(str) == true)
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
