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

static bool check_syntax(std::string _operations)
{
	std::stringstream ss(_operations);
	std::string word;
	int start = 0;
	int nbr_of_nbrs = 0;

	while (ss >> word)
	{
		if (isNumber(word))
			nbr_of_nbrs += 1;
		if (start == 0)
		{
			start = 1;
			continue;
		}
		if (nbr_of_nbrs < 2 && word.length() == 1 && (word[0] == '+' || word[0] == '-' || word[0] == '*' || word[0] == '/'))
			return (false);
		else if (nbr_of_nbrs >= 2  && word.length() == 1 && (word[0] == '+' || word[0] == '-' || word[0] == '*' || word[0] == '/'))
			nbr_of_nbrs -= 1;
	}
	return (true);
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

	if (!check_syntax(_operations))
	{
		std::cerr << "Error" << std::endl;
		return (false);
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
			if (!std::isdigit(word.c_str()[0]) && word.length() == 1)
				_op.push(word.c_str()[0]);
			else
				_num.push(std::atoi(word.c_str()));
		}
		else
		{
			if (!std::isdigit(word.c_str()[0]) && word.length() == 1)
				_op.push(word.c_str()[0]);
			else
				_num.push(std::atoi(word.c_str()));
		}
		i++;
	}
}

void	RPN::calculate(void)
{
	std::stringstream ss(_operations);
	std::string word;
	std::stack<float> numbers;
	
	while (ss >> word)
	{
		if (isNumber(word))
		{
			numbers.push(std::atoi(word.c_str()));
			continue;
		}
		float nbr1 = numbers.top();
		numbers.pop();
		float nbr2 = numbers.top();
		numbers.pop();
		if (word.length() == 1 && word[0] == '+')
			numbers.push(nbr2 + nbr1);
		else if (word.length() == 1 && word[0] == '-')
			numbers.push(nbr2 - nbr1);
		else if (word.length() == 1 && word[0] == '*')
			numbers.push(nbr2 * nbr1);
		else if (word.length() == 1 && word[0] == '/')
			numbers.push(nbr2 / nbr1);
	}
	std::cout << numbers.top() << std::endl;
}
