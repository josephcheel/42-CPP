#include "FragTrap.hpp"

int main(void)
{
	// Default Constructor
	FragTrap none;

	// String Constructors
	FragTrap Ally("Ally");
	FragTrap Enemy("Enemy");

	// Copy constructor
	FragTrap Copy(Ally);

	// Copy Assignment
	none = Enemy;

	// ClapTrap Ally attack ClapTrap Enemy
	Ally.attack("Enemy");
	
	// ClapTrap Enemy gets damage from ClapTrap Enemy and Repairs
	Enemy.takeDamage(Ally.getAttackDamage());
	Enemy.beRepaired(20);

	// ClapTrap Enemy attack ClapTrap Ally
	Enemy.attack("Ally");
	
	// ClapTrap Ally gets damage from ClapTrap Enemy. Ally Can´t Repair
	Ally.takeDamage(10);
	Ally.beRepaired(30);
	
	// Ally Can´t Attack
	Ally.attack("Enemy");

	// High Fives
	Ally.highFivesGuys();
}