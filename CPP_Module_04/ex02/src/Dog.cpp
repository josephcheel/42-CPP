#include "../inc/Dog.hpp"

Dog::Dog() : AbstractAnimal("Dog"), DogBrain(new Brain())
{
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog::~Dog()
{
	delete DogBrain;
	std::cout << "Dog desctructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : AbstractAnimal(copy.type), DogBrain(new Brain())
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy)
{
	if (this != &copy)
	{
		type = copy.type;
		DogBrain = copy.DogBrain;
	}
	return (*this);
}
	
void	Dog::makeSound(void) const
{
	std::cout << "woof... woof... woof" << std::endl;
}
