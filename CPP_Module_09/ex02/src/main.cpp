#include "../inc/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			std::cout << av[i] << " ";
		}
	}
}