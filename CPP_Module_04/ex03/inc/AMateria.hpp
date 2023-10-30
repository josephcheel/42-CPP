#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

class	AMateria {
	
	protected:
		std::string _type;

    public:
		AMateria();
		AMateria(std::string const & type);
		~AMateria(); // should be virtual?
		AMateria(AMateria &copy);

		AMateria &operator=(AMateria &copy);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif