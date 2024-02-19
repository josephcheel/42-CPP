#include "../inc/BitcoinExchange.hpp"



int	main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 0;
	}
	

	BitcoinExchange btc = BitcoinExchange(static_cast<std::string>(av[1]));
	
	// std::map<std::string, float> db = btc.getDataBaseMap();
	// for (std::map<std::string, float>::iterator it = db.begin() ; 
	// 	it != db.end(); ++it)
	// {
	// 	 std::cout << it->first << " " << it->second << "\n";
	// }

	std::map<std::string, float> in = btc.getInputMap();
	for (std::map<std::string, float>::iterator it = in.begin() ; 
		it != in.end(); ++it)
	{
		 std::cout << it->first << " " << it->second << "\n";
	}
}