#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"

class	Cure : public AMateria  {

    public:
		~Cure();
		Cure(Cure &copy);

		Cure &operator=(Cure &copy);
		// virtual AMateria* clone() const = 0;
		// virtual void use(ICharacter& target);
};

#endif