#include "../inc/DiamondTrap.hpp"

int main(void)
{
	std::cout << "\n------------OBJECT CONSTRUCTORS-------------\n" << std::endl;
	// Default Constructor
	DiamondTrap none;

	// String Constructors
	DiamondTrap Ally("Ally");
	DiamondTrap Enemy("Enemy");

	// Copy constructor
	DiamondTrap Copy(Ally);

	// Copy Assignment
	none = Enemy;

	std::cout << "\n------------OBJECT OWN METHODS-------------\n" << std::endl;
	// DiamondTrap Ally attack DiamondTrap Enemy
	Ally.attack("Enemy");
	
	// DiamondTrap Enemy gets damage from DiamondTrap Enemy and Repairs
	Enemy.takeDamage(Ally.getAttackDamage());
	Enemy.beRepaired(20);

	// DiamondTrap Enemy attack DiamondTrap Ally
	Enemy.attack("Ally");
	
	// DiamondTrap Ally gets damage from DiamondTrap Enemy. Ally Can´t Repair
	Ally.takeDamage(10);
	Ally.beRepaired(30);
	
	// Ally Can´t Attack
	Ally.attack("Enemy");

	// Guard Gate
	Ally.guardGate();

	// High fives
	Ally.highFivesGuys();

	// Who am I
	Ally.whoAmI();
	Enemy.whoAmI();
	
	std::cout << "\n------------OBJECT DESTRUCTOR-------------\n" << std::endl;
	return (0);
}
