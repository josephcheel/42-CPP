#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter {
	protected:
		AMateria *materias[4];
		std::string _name;
		int _nbrMateria;
	public:
		Character();
		Character(const std::string name);
		Character(Character &copy);
		~Character();
		
		Character &operator=(Character &copy);

		std::string const & getName() const;
		std::string const & getMateriaType(int idx) const;
		AMateria const  *getMateria() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void printMaterias();
};

#endif