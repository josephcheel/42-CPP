# include <iostream>
# include <string>
# include "../inc/ScalarConverter.hpp"


int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	ScalarConverter::convert((std::string)av[1]);
}
