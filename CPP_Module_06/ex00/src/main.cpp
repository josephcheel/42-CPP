# include <iostream>
# include <string>
# include "../inc/ScalarConverter.hpp"

// bool	isnum(std::string str)
// {
// 	size_t lenght = str.length();
// }

int	main(int ac, char **av)
{
	// std::string nbr;

	// if (ac <= 1)
	// 	return 0;
	// nbr = av[1];
	// if (nbr[nbr.length() - 1] == 'f')
	// {
	
	// }
	(void)ac;
	(void)av;
	if (ac != 2)
		return (0);
	ScalarConverter Converter;
	Converter.convert((std::string)av[1]);

		
}
