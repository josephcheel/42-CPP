#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : name(name), Weapon(nullptr)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void HumanB::setWeapon(class Weapon &Weapon)
{
	this->Weapon = &Weapon;
	return ;
}

void HumanB::attack(void)
{
	if (!this->Weapon)
		std::cout << "NO WEAPON";
	else
		std::cout << this->name << " attacked with " << this->Weapon->getType() << std::endl;
	return ;
}