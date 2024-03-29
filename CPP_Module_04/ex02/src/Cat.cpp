#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

Cat::Cat() : AbstractAnimal("Cat"), CatBrain(new Brain())
{
	std::cout << "Cat Default constructor called" << std::endl;
}
Cat::Cat::~Cat()
{
	delete CatBrain;
	std::cout << "Cat desctructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : AbstractAnimal(copy.type), CatBrain(new Brain())
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &copy)
{
	if (this != &copy)
	{
		type = copy.type;
		this->CatBrain = copy.CatBrain;
	}
	return (*this);
}
	
void	Cat::makeSound(void) const
{
	std::cout << "meow... meow... meow" << std::endl;
}
