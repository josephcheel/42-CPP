#include "../inc/AMateria.hpp"


AMateria::AMateria()
{
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &copy)
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

void	AMateria::setType(std::string type)
{
	this->_type = type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << _type << " used on " << target.getName() << std::endl;
}

AMateria* AMateria::clone() const
{
	return (new AMateria(*this));
}

