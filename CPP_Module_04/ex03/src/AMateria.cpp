#include "../inc/AMateria.hpp"


AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria desctructor called" << std::endl;
}

AMateria::AMateria(AMateria &copy) : _type(copy._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria &copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

std::string const & AMateria::getType() const //Returns the materia type
{
	return (_type);
}