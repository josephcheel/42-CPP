#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Joseph("Joseph");
	ClapTrap Enemy("Enemy");

	Joseph.attack("Enemy");
	Enemy.takeDamage(2);
	Enemy.beRepaired(2);

	// Enemy.attack("Joseph");
	// Joseph.takeDamage(10);
	// Joseph.beRepaired(2);

	
}