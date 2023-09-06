#include "../inc/Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Empty Default Weapon constructor called" << std::endl;
}

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << "Default Weapon constructor called" << std::endl;
}

Weapon::~Weapon() 
{
	std::cout << "Weapon destructor called" << std::endl;
}		

const std::string &Weapon::getType()
{
	return (this->type);
}

void  Weapon::setType(std::string type)
{
	this->type = type;
}