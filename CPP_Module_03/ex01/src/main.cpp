#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\n------------OBJECT CONSTRUCTORS-------------\n" << std::endl;
	// Default Constructor
	ScavTrap none;

	// String Constructors
	ScavTrap Ally("Ally");
	ScavTrap Enemy("Enemy");

	// Copy constructor
	ScavTrap Copy(Ally);

	// Copy Assignment
	none = Enemy;

	std::cout << "\n------------OBJECT OWN METHODS-------------\n" << std::endl;
	// ClapTrap Ally attack ScavTrap Enemy
	Ally.attack("Enemy");
	
	// ScavTrap Enemy gets damage from ScavTrap Enemy and Repairs
	Enemy.takeDamage(Ally.getAttackDamage());
	Enemy.beRepaired(20);

	// ScavTrap Enemy attack ScavTrap Ally
	Enemy.attack("Ally");
	
	// ScavTrap Ally gets damage from ScavTrap Enemy. Ally Can´t Repair
	Ally.takeDamage(10);
	Ally.beRepaired(30);
	
	// Ally Can´t Attack
	Ally.attack("Enemy");

	// Guard Gate
	Ally.guardGate();
	
	std::cout << "\n------------OBJECT DESTRUCTOR-------------\n" << std::endl;
	return (0);
}