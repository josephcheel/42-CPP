#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Ally("Ally");
	ClapTrap Enemy("Enemy");

	// ClapTrap Ally attack ClapTrap Enemy
	Ally.attack("Enemy");
	// ClapTrap Enemy gets damage from ClapTrap Enemy
	Enemy.takeDamage(Ally.getAttackDamage());
	// Enemy Repairs
	Enemy.beRepaired(20);

	// ClapTrap Enemy attack ClapTrap Ally
	Enemy.attack("Joseph");
	// ClapTrap Ally gets damage from ClapTrap Enemy
	Ally.takeDamage(10);
	// Ally Can´t Repair
	Ally.beRepaired(30);
	// Ally Can´t Repair
	Ally.attack("Enemy");

}
