#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Default constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice desctructor called" << std::endl;
}

Ice::Ice(Ice &copy) : AMateria(copy)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice &copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

Ice* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}