#include "../inc/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac > 1)
	{
		PmergeMe Instance;

		if (!Instance.checker(ac, av))
			return 1;
		Instance.initialization(ac, av);

		Instance.mergeInsertSort();
		
		Instance.print_result();
	}
}