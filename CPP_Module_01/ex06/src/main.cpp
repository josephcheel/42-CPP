#include "../inc/Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	Harl Harl;

	Harl.filtered_complain(av[1]);
	return 0;
}