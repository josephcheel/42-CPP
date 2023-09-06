#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB {

	private: 
		Weapon *Weapon;
		std::string name;
	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(class Weapon &Weapon);
		void attack(void);
};

#endif