#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>

class Span {
	private:
		std::list numbers;
	public:
		Span();
		Span(unsigned int N);
		
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		
		~Span();

};
#endif
