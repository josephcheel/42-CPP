#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : Weapon(nullptr), name(name)
{
	std::cout << "Default HumanB constructor called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}

void HumanB::setWeapon(class Weapon &Weapon)
{
	this->Weapon = &Weapon;
}

void HumanB::attack(void)
{
	if (!this->Weapon)
		std::cout << "NO WEAPON";
	else
		std::cout << this->name << " attacked with " << this->Weapon->getType() << std::endl;
	return ;
}