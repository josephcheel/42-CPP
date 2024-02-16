#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

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
		void	addRange(int start, int end);
		void	addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();
};
#endif
