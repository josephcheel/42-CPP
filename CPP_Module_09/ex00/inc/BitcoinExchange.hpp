#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
#include <vector>
# include <map>

class BitcoinExchange {
	private:
		std::fstream		dbf;
		std::fstream		inputf;
		std::map<std::string, float>	dbMap;
		std::map<std::string, float>	inputMap;
	public:
		BitcoinExchange();

		BitcoinExchange(const std::string &input);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		~BitcoinExchange();

		std::map<std::string, float>	getDataBaseMap() const;
		std::map<std::string, float>	getInputMap() const;
		float	getDBValue(const std::string &date) const;
		float	getInValue(const std::string &date) const;

		bool	opendb();
		bool	openinput(const std::string &filename);
		void	chargeDb();
		void	chargeInput();
};

#endif