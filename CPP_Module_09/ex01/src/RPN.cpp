#include "../inc/RPN.hpp"

RPN::RPN()
{
	std::cout << "RPN default constructor" << std::endl;
}

RPN::~RPN()
{
	std::cout << "RPN destructor" << std::endl;
}

RPN::RPN(const std::string &operations) : _operations(operations)
{
	std::cout << "RPN constructor" << std::endl;
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
	{
		this->_operations = copy._operations;
		this->_num = copy._num;
		this->_op = copy._op;
	}
	return (*this);
}

static bool isNumber(std::string &str)
{
	size_t start = 0;
	
	if (str[start] == '+' || str[start] == '-')
		start = 1;
	if (start == str.size())
		return false;
	for (size_t i = start; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i])) 
			return false;
	}
	return true;
}

bool	RPN::ReversePolishNotationSyntax()
{
	std::stringstream ss(_operations);
	std::string word;
	
	while (ss >> word)
	{
		if (!isNumber(word) && !(word.length() == 1 && (word[0] == '+' || word[0] == '-' || word[0] == '*' || word[0] == '/')))
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
	
	}

	std::stack<int>::size_type nbr_of_nbrs =  _num.size();
	if (nbr_of_nbrs - 1 == _op.size())
		return (true);
	else
	{
		std::cerr << "Error" << std::endl;
		return (false);
	}
}

void	RPN::process()
{
	std::stringstream ss(_operations);
	std::string word;
	int i = 0;
	
	while (ss >> word)
	{
		if (i == 0 || i == 1 || i % 2 != 0)
		{
			if (!std::isdigit(word.c_str()[0]))
				_op.push_back(word.c_str()[0]);
			else
				_num.push_back(std::atoi(word.c_str()));
		}
		else
		{
			if (!std::isdigit(word.c_str()[0]))
				_op.push_back(word.c_str()[0]);
			else
				_num.push_back(std::atoi(word.c_str()));
		}
		i++;
	}
}

void	RPN::calculate(void)
{
	std::stringstream ss(_operations);
	std::string word;
	std::vector<int> numbers;
	
	while (ss >> word)
	{
		if (isNumber(word))
		{
			numbers.push_back(std::atoi(word.c_str()));
			continue;
		}
		int nbr1 = numbers.back();
		numbers.pop_back();
		int nbr2 = numbers.back();
		numbers.pop_back();
		if (word.length() == 1 && word[0] == '+')
			numbers.push_back(nbr2 + nbr1);
		else if (word.length() == 1 && word[0] == '-')
			numbers.push_back(nbr2 - nbr1);
		else if (word.length() == 1 && word[0] == '*')
			numbers.push_back(nbr2 * nbr1);
		else if (word.length() == 1 && word[0] == '/')
			numbers.push_back(nbr2 / nbr1);
	}
	std::cout << numbers.back() << std::endl;
}

void	RPN::printnum()
{
	std::cout << "num: ";
	for (std::vector<int>::size_type i = 0; i < _num.size(); ++i)
		std::cout << _num[i] << " ";
	std::cout << "\n";
}

void	RPN::printop()
{
	std::cout << "op: ";
	for (std::vector<char>::size_type i = 0; i < _op.size(); ++i)
		std::cout << _op[i] << " ";
	std::cout << "\n";
}