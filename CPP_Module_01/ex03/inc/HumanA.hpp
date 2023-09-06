#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA {

	private:
		Weapon &Weapon;
		std::string name;
	public:
		HumanA(std::string name, class Weapon &Weapon);
		~HumanA();
		void attack(void);
};
#endif