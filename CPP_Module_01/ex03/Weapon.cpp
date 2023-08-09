#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
	return ;
}

Weapon::~Weapon() 
{
	return ;
}		

const std::string &Weapon::getType()
{
	return (this->type);
}

void  Weapon::setType(std::string type)
{
	this->type = type;
	return ;
}

// Weapon *Weapon(std::string type)
// {
// 	Weapon newWeapon = new Weapon;
// 	newWeapon.
// 	return (newWeapon)
// }