#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <cstring>
# include <cstdlib>
# include <fstream>
# include <string>
# include <map>

class BitcoinExchange {
	private:
		std::fstream		dbf;
		std::fstream		inputf;
		std::map<std::string, float>	dbMap;
	public:
		BitcoinExchange();

		BitcoinExchange(const std::string &input);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		~BitcoinExchange();

		std::map<std::string, float>	getDataBaseMap() const;
		float	getDBValue(const std::string &date) const;
		
		bool	opendb();
		bool	openinput(std::string filename);
		void	chargeDb();
		void	chargeInput();

		float	find_closest_min_value(std::string date);
};

#endif