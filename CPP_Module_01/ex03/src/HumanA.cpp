#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, class Weapon &Weapon) : Weapon(Weapon), name(name)
{
	std::cout << "Default HumanA constructor called" << std::endl;
}
HumanA::~HumanA()
{
	std::cout << "HumanA destructor called" << std::endl;
}
void	HumanA::attack(void)
{
	std::cout << this->name << " attacked with " << this->Weapon.getType() << std::endl;
}