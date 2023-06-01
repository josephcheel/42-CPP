#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int arg = 1; arg < ac; arg++)
	{
		string str = av[arg];
		for (int c = 0; c < int(str.length()); c++)
		{
			if (std::islower(av[arg][c]))
				std::cout <<  char(std::toupper(av[arg][c]));
			else
				std::cout << av[arg][c];
		}
	}
	std::cout << std::endl;
}