#include "../inc/BitcoinExchange.hpp" 

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string &input)
{
	if (!this->opendb())
	{
		std::cerr << "Error: database data.csv not found" << std::endl;
		return ;
	}
	if (!this->openinput(input))
	{
		std::cerr << "Error: could not open file [" << input << "]" << std::endl;
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
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	if (dbf)
		dbf.close();
	if (inputf)
		inputf.close();
	if (dbMap.size() > 0)
		dbMap.clear();
	std::cout << "BitcoinExchange Destructor called" << std::endl;
}

std::map<std::string, float>	BitcoinExchange::getDataBaseMap() const
{
	return (dbMap);
}

float	BitcoinExchange::getDBValue(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = dbMap.find(date);
	if (it != dbMap.end())
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

static bool isNumber(std::string str) {
  for (int i = 0; str[i]; i++) {
    if (std::isdigit(str[i]) == 0) 
		return false;
  }
  return true;
}

static bool	isDayValid(std::string daystr, std::string monthstr, std::string yearstr)
{
	int day = std::atoi(daystr.c_str());
	int month = std::atoi(monthstr.c_str());
	int year = std::atoi(yearstr.c_str());

	if (year > 0)
	if (day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			return false;
	if (month == 2) {
		// Check for leap year
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			if (day > 29)
			return false;
		} else {
			if (day > 28)
			return false;
		}
	}
	return (true);
}

static bool	is_date_valid(std::string date)
{
	std::string day;
	std::string month;
	std::string year;

	std::stringstream ss(date);
	if (std::getline(ss, year, '-') &&
		std::getline(ss, month, '-') &&
		std::getline(ss, day, '-'))
	{
		if (!(isNumber(day) && isNumber(month) && isNumber(year) && isDayValid(day, month, year)))
			return (false);
	}
	return (true);
}

float	BitcoinExchange::find_closest_min_value(std::string date)
{
	std::map<std::string, float>::iterator prev = dbMap.begin();

	for (std::map<std::string, float>::iterator it = dbMap.begin(); it != dbMap.end(); ++it)
	{
		if (date < it->first)
		{
			if (it == prev)
				std::exception();
			else
				return (prev->second);
		}
		prev = it;
	}
	return (0);
}

void	BitcoinExchange::chargeInput()
{
	
	std::string	date;
	std::string	value;
	std::string	line;
	float final_value;
	
	// while (inputf)
	// {
	// }
	while (std::getline(inputf, line, '\n')) 
	{
		// std::string::size_type	firstLetter = line.find_first_not_of(" \t\n");
		// std::string::size_type	lastLetter = line.find_last_not_of(" \t\n");
		// line = line.substr(firstLetter);
		// line = line.substr(0, lastLetter + 1);

		std::string::size_type	Firstpipe = line.find_first_of(" |\n\t");
		std::string::size_type	Lastpipe = line.find_last_of(" |\n\t");
		date = line.substr(0, Firstpipe);
		value = line.substr(Lastpipe + 1, line.length());

		// std::cout << "$LINE: " << line << "$" << std::endl;
		// std::cout << "$" << date << "$" << std::endl;
		// std::cout << "$" << value << "$" << std::endl;
		if (date == "date" && value == "value")
			continue;

		if (!is_date_valid(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		else if (std::atof(value.c_str()) > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		if (dbMap.find(date) != dbMap.end())
			final_value = dbMap[date] * std::atof(value.c_str());
		else
		{
			// std::string newDate = find_closest_min_value(date);
			// while (newDate.length() != 0)
			// {
			// 	std::string date = find_closest_min_value(newDate);
			// }
			final_value = BitcoinExchange::find_closest_min_value(date) * std::atof(value.c_str());
		}
		if (final_value >= 0)
			std::cout << date << " => " << value << " = " << final_value << std::endl;
		else if (final_value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		// std::cout << std::atof(value.c_str()) << " " << std::numeric_limits<int>::max() << std::endl;
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