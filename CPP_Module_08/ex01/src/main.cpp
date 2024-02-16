# include <iostream>
# include "../inc/Span.hpp"


int	main(void)
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(10000);
		sp.addRange(0, 10000);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		
		/* AddRange() Method using a range of iterators*/
		Span sp2 = Span(10000);

		std::vector<int> tmp = sp.getVector();
		sp2.addRange(tmp.begin(), tmp.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		
	}
	return (0);
}