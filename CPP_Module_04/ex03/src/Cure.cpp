#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{ 
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &copy) 
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
	std::cout << "Cure copy Assginment called" << std::endl;
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}