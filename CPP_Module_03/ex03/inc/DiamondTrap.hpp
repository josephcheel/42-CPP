#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	protected:
		DiamondTrap();
		std::string _name;
	public:
	
		DiamondTrap(std::string const &name);
		~DiamondTrap(void);

		DiamondTrap(DiamondTrap &copy);

		DiamondTrap& operator=(DiamondTrap &copy);

		void whoAmI();
		void attack(const std::string& target);
};

#endif
