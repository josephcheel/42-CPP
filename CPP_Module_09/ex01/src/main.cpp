# include "../inc/RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage: ./RPN \"number number arithmetic-operator...\"" << std::endl;
		std::cerr << "usage: example: ./RPN 7 7 * 2" << std::endl;
		return 0;
	}
	RPN instance(static_cast<std::string>(av[1]));

	instance.process();
	// instance.printnum();
	// instance.printop();
	if (!instance.ReversePolishNotationSyntax())
		return (0);
	instance.calculate();
	
	// RPN::calculate(static_cast<std::string>(av[1]));
}