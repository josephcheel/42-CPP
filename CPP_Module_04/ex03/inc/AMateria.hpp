#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string _type;

    public:
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(const AMateria &copy);

		AMateria &operator=(const AMateria &copy);

		void	setType(std::string const type);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif