#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap Constructor called" << std::endl;
	_name = name;
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
}
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}
DiamondTrap::DiamondTrap(DiamondTrap &copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(DiamondTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_HitPoints =  copy.getHitPoints();
		_EnergyPoints = copy.getEnergyPoints();
		_AttackDamage = copy.getAttackDamage();
	}
	return (*this);
}
void DiamondTrap::whoAmI()
{	
	std::cout << "DiamondTrap name: " << _name << " ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}