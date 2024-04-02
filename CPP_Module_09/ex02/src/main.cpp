#include "../inc/PmergeMe.hpp"

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

static bool	ft_checker(int ac, const char **nbrs)
{
	for (int i = 0; i < ac; i++)
	{
		if (!isNumber(static_cast<std::string>(nbrs[i])))
	}
}
int main(int ac, char **av)
{
	std::stack<int> vect;
	std::list<int> lst;

	if (ac > 1)
	{
		if (!ft_checker(ac, av))
			return 1;
		for (int i = 1; i < ac; i++)
		{
			std::cout << av[i] << " ";
		}
	}
}