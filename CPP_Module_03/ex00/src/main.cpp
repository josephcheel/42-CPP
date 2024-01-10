#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "\n------------OBJECT CONSTRUCTORS-------------\n" << std::endl;
	// Default Constructor
	ClapTrap none;

	// String Constructors
	ClapTrap Ally("Ally");
	ClapTrap Enemy("Enemy");

	// Copy constructor
	ClapTrap Copy(Ally);

	// Copy Assignment
	none = Enemy;

	std::cout << "\n------------OBJECT OWN METHODS-------------\n" << std::endl;
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
	std::cout << "\n------------OBJECT DESTRUCTOR-------------\n" << std::endl;
	return (0);
}
