#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <climits>
# include <algorithm>
# include <cstdlib>

class Span {
	private:
		std::vector<int>	v;
		unsigned int		_MaxSize;
	public:
		Span();
		Span(unsigned int N);
		
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		
		~Span();

		unsigned int		getMaxSize() const;
		std::vector<int>	getVector() const;
		void	addNumber(int add);
		void	addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();

	class TooFewElements : public std::exception {
		public:
			virtual const char * what() const throw();
	};

	class TooManyElements : public std::exception {
		public:
			virtual const char * what() const throw();
	};
};
#endif
