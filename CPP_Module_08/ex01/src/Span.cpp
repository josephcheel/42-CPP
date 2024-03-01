#include "../inc/Span.hpp"

Span::Span() : _MaxSize(0)
{
	std::cout << "Span Default called" << std::endl;
}

Span::Span(unsigned int N) : _MaxSize(N)
{
	std::cout << "Span Constructor called" << std::endl;
}
		
Span::Span(const Span &copy)
{
	std::cout << "Span Copy Constructor called" << std::endl;
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	std::cout << "Span Copy Assignment called" << std::endl;
	if (this != &copy)
	{
		this->v = copy.v;
		this->_MaxSize = copy._MaxSize;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

unsigned int	Span::getMaxSize() const
{
	return (_MaxSize);
}

std::vector<int>	Span::getVector() const
{
	return (v);
}

void	Span::addNumber(int add)
{
	if (v.size() < _MaxSize)
		v.push_back(add);
	else
		throw TooManyElements();
}

int		Span::shortestSpan()
{
	int	shortest = INT_MAX;

	if (v.size() <= 1)
		throw TooFewElements();
	std::sort(v.begin(), v.end());
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		std::vector<int>::iterator it2 = it;
		it2++;
		float distance;
		if (*it2 > *it)
			distance = *it2 - *it;
		else
			distance =  *it - *it2;
		if (distance < shortest)
		{
			shortest = distance;
			if (shortest <= 1)
				return (shortest);	
		}
	}
	return (shortest);
}

int		Span::longestSpan()
{
	if (v.size() <= 1)
		throw TooFewElements();
	int	shortest = *std::min_element(v.begin(), v.end());
	int	longest = *std::max_element(v.begin(), v.end());

	return (abs(longest - shortest));
}

void	Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (v.size() + static_cast<int>(std::distance(start, end)) <= _MaxSize)
		v.insert(v.end(), start, end);
	else
		throw TooManyElements();
}

const char *Span::TooFewElements::what() const throw()
{
	return ("[TooFewElements Exception]");
}

const char *Span::TooManyElements::what() const throw()
{
	return ("[TooManyElements Exception]");
}
