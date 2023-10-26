#include "FragTrap.hpp"

int main(void)
{
	FragTrap Joseph("Joseph");
	FragTrap Enemy("Enemy");

	Joseph.attack("Enemy");
	Enemy.takeDamage(Joseph.getAttackDamage());
	Enemy.beRepaired(2);
	Enemy.highFivesGuys();
	// Enemy.attack("Joseph");
	// Joseph.takeDamage(10);
	// Joseph.beRepaired(2);

}