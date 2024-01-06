#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter {
	protected:
		AMateria *materias[4];
		//std::array<AMateria, 4> materias;
		std::string _name;
	public:
		Character();
		Character(const std::string name);
		Character(Character &copy);
		~Character();
		
		Character &operator=(Character &copy);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif