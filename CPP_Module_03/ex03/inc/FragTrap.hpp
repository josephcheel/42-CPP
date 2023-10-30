#ifndef FRAGTRAP__HPP
# define FRAGTRAP__HPP
# include "ClapTrap.hpp"
// # include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(FragTrap const &copy);
		FragTrap &operator=(FragTrap &copy);
		void highFivesGuys(void);
	protected:
		FragTrap(void);
};

#endif
