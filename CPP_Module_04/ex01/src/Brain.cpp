#include "../inc/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain desctructor called" << std::endl;
}

Brain::Brain(Brain const &copy) : ideas(copy.ideas)
{
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &copy)
{
	std::cout << "Brain copy operator assignment called" << std::endl;
	if (this != &copy)
	{
		ideas = copy.ideas;
	}
	return (*this);
}
