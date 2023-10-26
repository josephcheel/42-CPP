#include "../inc/AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal(std::string _type) : type(_type)
{
	std::cout << "AbstractAnimal type Default constructor called" << std::endl;
}

AbstractAnimal::~AbstractAnimal( void )
{
	std::cout << "AbstractAnimal desctructor called" << std::endl;
	return ;
}

std::string		AbstractAnimal::getType() const
{
	return(type);
}




// #include "../inc/Animal.hpp"

// Animal::Animal() : type("NoAnimal")
// {
// 	std::cout << "Animal empty Default constructor called" << std::endl;
// }

// Animal::Animal(std::string _type) : type(_type)
// {
// 	std::cout << "Animal type Default constructor called" << std::endl;
// }

// Animal::~Animal( void )
// {
// 	std::cout << "Animal desctructor called" << std::endl;
// 	return ;
// }

// Animal::Animal(Animal const &copy) : type(copy.type)
// {
// 	std::cout << "Animal copy constructor called" << std::endl;
// }

// Animal const &Animal::operator=(Animal const &copy)
// {
// 	std::cout << "ANimal copy operator assignment called" << std::endl;
// 	if (this != &copy)
// 	{
// 		type = copy.type;
// 	}
// 	return (*this);
// }

// std::string		Animal::getType() const
// {
// 	return(type);
// }

// void	Animal::makeSound(void) const
// {
// 	std::cout << "... Silence ..." << std::endl;
// }
