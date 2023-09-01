#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ScavTrap const &copy);
		ScavTrap &operator=(ScavTrap &copy);
		void attack(const std::string& target);
		void guardGate();
	protected:
		ScavTrap(void);
};


#endif
