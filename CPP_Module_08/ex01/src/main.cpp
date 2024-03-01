# include <iostream>
# include "../inc/Span.hpp"


int	main(void)
{
	std::cout << "------------ORTHODOX CANONICAL FORM---------" << std::endl;
	{
		/*Default Constructor*/
		Span sp;
		std::cout << sp.getMaxSize() << std::endl;

		/*Parameter Constructor*/
		Span sp2(5);
		std::cout << sp2.getMaxSize() << std::endl;

		/*Copy Constructor*/
		Span sp3(sp2);
		std::cout << sp3.getMaxSize() << std::endl;

		/*Copy Assignment*/
		sp = sp2;
		std::cout << sp.getMaxSize() << std::endl;
	}
	std::cout << "--------------TEST SUBJECT-------------------" << std::endl;
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
	std::cout << "--------------ADD_RANGE----------------------" << std::endl;
	{
		int initialValues[] = {1, 10, 21, 32, 43, 54, 65 ,76 ,87 ,98};
		size_t size = sizeof(initialValues) / sizeof(initialValues[0]);
		
		std::vector<int> sp(initialValues, initialValues + size);

		for (std::vector<int>::iterator it = sp.begin(); it != sp.end(); ++it)
			std::cout << *it << std::endl;
		
		/* AddRange() Method using a range of iterators*/
		Span sp2 = Span(10000);
		
		sp2.addRange(sp.begin(), sp.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	std::cout << "--------------ADD_RANGE-----------------------" << std::endl;
	{
		/* AddRange() Method using a range of iterators*/
		Span sp2 = Span(5);

		std::vector<int> tmp;
		tmp.push_back(5);
		tmp.push_back(3);
		tmp.push_back(17);
		tmp.push_back(9);
		tmp.push_back(11);
	
		sp2.addRange(tmp.begin(), tmp.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	return (0);
}
