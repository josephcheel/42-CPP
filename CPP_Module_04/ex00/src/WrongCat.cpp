#include "../inc/WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}
WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat desctructor called" << std::endl;
}

WrongCat::WrongCat( std::string _type ) : WrongAnimal(_type)
{
		std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const &copy ) : WrongAnimal(copy.type)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=( WrongCat const &copy )
{
	std::cout << "WrongCat copy operator assignment called" << std::endl;
	if (this != &copy)
	{
		type = copy.type;
	}
	return (*this);
}


void	WrongCat::makeSound(void) const
{
		std::cout << "Weow... Weow... Weow" << std::endl;
}