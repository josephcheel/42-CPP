#include "../inc/DiamondTrap.hpp"

int main(void)
{
	DiamondTrap Joseph("Joseph");
	DiamondTrap Enemy("Enemy");

	Joseph.whoAmI();
	Joseph.attack("Enemy");
	Enemy.takeDamage(10);
	Enemy.beRepaired(2);

	// Enemy.attack("Joseph");
	// Joseph.takeDamage(10);
	// Joseph.beRepaired(2);

}
