#include "FragTrap.hpp"

int main(void)
{
	std::cout << "\n------------OBJECT CONSTRUCTORS-------------\n" << std::endl;
	// Default Constructor
	FragTrap none;

	// String Constructors
	FragTrap Ally("Ally");
	FragTrap Enemy("Enemy");

	// Copy constructor
	FragTrap Copy(Ally);

	// Copy Assignment
	none = Enemy;

	std::cout << "\n------------OBJECT OWN METHODS-------------\n" << std::endl;
	// FragTrap Ally attack FragTrap Enemy
	Ally.attack("Enemy");
	
	// FragTrap Enemy gets damage from FragTrap Enemy and Repairs
	Enemy.takeDamage(Ally.getAttackDamage());
	Enemy.beRepaired(20);

	// FragTrap Enemy attack FragTrap Ally
	Enemy.attack("Ally");
	
	// FragTrap Ally gets damage from FragTrap Enemy. Ally Can´t Repair
	Ally.takeDamage(10);
	Ally.beRepaired(30);
	
	// Ally Can´t Attack
	Ally.attack("Enemy");

	// High Fives
	Ally.highFivesGuys();

	std::cout << "\n------------OBJECT DESTRUCTOR-------------\n" << std::endl;
	return (0);
}