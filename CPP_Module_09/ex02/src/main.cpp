#include "../inc/PmergeMe.hpp"
# include <array>

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

	// int swap;
	// for (std::array<int, 5>::iterator it = a.begin(); it != a.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// swap = *a.begin();
	// *a.begin() = *a.begin() + 1;
	// *(a.begin() + 1) = swap;
	// for (std::array<int, 5>::iterator it = a.begin(); it != a.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

}