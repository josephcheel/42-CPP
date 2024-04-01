#include "../inc/BitcoinExchange.hpp"



int	main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 0;
	}
	BitcoinExchange btc = BitcoinExchange(static_cast<std::string>(av[1]));
}