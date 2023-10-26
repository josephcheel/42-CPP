#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Joseph("Joseph");
	ScavTrap Enemy("Enemy");

	Joseph.attack("Enemy");
	Enemy.takeDamage(2);
	Enemy.beRepaired(2);
	Enemy.beRepaired(2);
	Enemy.guardGate();
	// Enemy.attack("Joseph");
	// Joseph.takeDamage(10);
	// Joseph.beRepaired(2);

	
}