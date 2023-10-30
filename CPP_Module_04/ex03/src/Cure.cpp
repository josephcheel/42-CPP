#include "../inc/Cure.hpp"


Cure::Cure() : _type("cure")
{
	std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(Cure &copy) : _type("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}


Cure &Cure::operator=(Cure &copy)
{
	// std::cout << "Cure destructor called" << std::endl;
}
AMateria* Cure::clone() const
{

}
void Cure::use(ICharacter& target)
{

}