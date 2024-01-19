#include "../inc/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &copy)
{
	*this = copy;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &copy)
{
	std::cout << "Brain copy operator assignment called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
		{
			if (!copy.ideas[i].empty())
				ideas[i] = copy.ideas[i];
		}
	}
	return (*this);
}
