#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"

class	Cure : public AMateria  {

    public:	
		Cure();
		Cure(Cure &copy);
		~Cure();

		Cure &operator=(Cure &copy);
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif