#include "../inc/BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const std::string &input)
{
	if (!this->opendb())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}
	if (!this->openinput(input))
	{
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}

	this->chargeDb();
	this->chargeInput();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
		this->dbMap.clear();
		this->dbMap = copy.dbMap;
		this->inputMap.clear();
		this->inputMap = copy.inputMap;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	if (dbf)
		dbf.close();
	if (inputf)
		inputf.close();
	std::cout << "BitcoinExchange Destructor called" << std::endl;
}

std::map<std::string, float>	BitcoinExchange::getDataBaseMap() const
{
	return (dbMap);
}

std::map<std::string, float>	BitcoinExchange::getInputMap() const
{
	return (inputMap);
}
float	BitcoinExchange::getDBValue(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = dbMap.find(date);
	if (it != dbMap.end())
		return (it->second);
	return (-1);
}
float	BitcoinExchange::getInValue(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = inputMap.find(date);
	if (it != inputMap.end())
		return (it->second);
	return (-1);
}

bool	BitcoinExchange::opendb()
{
	dbf.open("data.csv", std::ios::in);
	if (!dbf)
		return (false);
	return (true);
}

bool	BitcoinExchange::openinput(const std::string &filename)
{
	inputf.open(filename, std::ios::in);
	if (!inputf)
		return (false);
	return (true);
}

void	BitcoinExchange::chargeInput()
{
	
	std::string date;
	std::string value;
	std::string	line = "A";
	
	while (inputf)
	{
		int			i = 0;
		while (inputf)
		{
			inputf >> line;
			if (line == "date" || line == "value")
				break;
			else if (line == "|" && i == 0)
				i++;
			else if (i == 0 && !line.empty())
			{
				date = line;
				i++;
			}
			else if (i == 2 && !line.empty())
			{
				value = line;
				i++;
			}
			if (i >= 3)
				break ;
		}
		if (!date.empty() || !value.empty())
			inputMap[date] = std::atoi(value.c_str());
	}
}

void	BitcoinExchange::chargeDb()
{
	char *ptr;
	std::string date;
	std::string value;

	std::string	line;
	while (dbf)
	{
		dbf >> line;
		ptr = std::strtok(const_cast<char *>(line.c_str()), ",");
		date = ptr;
		ptr = strtok(NULL, ",");
		if (ptr)
		{
			value = ptr;
			if (dbMap.find(date) == dbMap.end())
				dbMap[date] = std::atof(value.c_str());
		}
	}
}