#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("NoWrongAnimal")
{
	std::cout << "WrongAnimal empty Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal desctructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string _type ) : type(_type)
{
	std::cout << "WrongAnimal type Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &copy ) : type(copy.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}
	
WrongAnimal	&WrongAnimal::operator=( WrongAnimal const &copy )
{
	if (this != &copy)
	{
		type = copy.type;
	}
	std::cout << "WrongAnimal copy operator assignment called" << std::endl;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void		WrongAnimal::makeSound( void ) const
{
	std::cout << "... Wrong Animal Silence ..." << std::endl;
}