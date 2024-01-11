#include "../inc/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
}
Cat::Cat::~Cat()
{
	std::cout << "Cat desctructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy.type)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &copy)
{
	std::cout << "Cat copy operator assignment called" << std::endl;
	if (this != &copy)
	{
		type = copy.type;
	}
	return (*this);
}
	
void	Cat::makeSound(void) const
{
	std::cout << "meow... meow... meow" << std::endl;
}