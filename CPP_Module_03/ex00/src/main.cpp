#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Joseph("Joseph");
	ClapTrap Enemy("Enemy");

	Joseph.attack("Enemy");
	Enemy.takeDamage(Joseph.getAttackDamage());
	std::cout <<  Joseph.getName() << " has " << Joseph.getEnergyPoints() << " energy points left" << std::endl;
	Enemy.beRepaired(20);

	Enemy.attack("Joseph");
	Joseph.takeDamage(10);
	// Joseph.beRepaired(2);	
}