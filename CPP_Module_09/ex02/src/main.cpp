#include "../inc/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac > 1)
	{
		PmergeMe Instance;

		if (!Instance.checker(ac, av))
			return 1;
		Instance.initialization(ac, av);

		Instance.sort();
		
		Instance.print_result();
	}
}