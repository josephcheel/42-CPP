#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "AMateria.hpp"

class	Ice : public AMateria {

    public:
		~Ice();
		Ice(Ice &copy);

		Ice &operator=(Ice &copy);
		AMateria* clone() const = 0;
		void use(ICharacter& target);
};

#endif