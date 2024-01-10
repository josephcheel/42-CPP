#ifndef FRAGTRAP__HPP
# define FRAGTRAP__HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class FragTrap : public ClapTrap {

	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap &operator=(const FragTrap &copy);
		void highFivesGuys(void);
	protected:
		
};

#endif