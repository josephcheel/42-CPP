#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, class Weapon &Weapon) : name(name), Weapon(Weapon)
{
	return ;
}
HumanA::~HumanA()
{
	return ;
}
void	HumanA::attack(void)
{
	std::cout << this->name << " attacked with " << this->Weapon.getType() << std::endl;
}