#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
}
Dog::Dog::~Dog()
{
	std::cout << "Dog desctructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy.type)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy)
{
	if (this != &copy)
	{
		type = copy.type;
	}
	return (*this);
}
	
void	Dog::makeSound(void) const
{
	std::cout << "woof... woof... woof" << std::endl;
}