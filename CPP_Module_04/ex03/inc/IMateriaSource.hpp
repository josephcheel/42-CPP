#ifndef IMATERIA_SOURCE_HPP
# define IMATERIA_SOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource {

	public:
			virtual ~IMateriaSource() {}
			virtual void learnMateria(AMateria*) = 0;
			virtual AMateria* createMateria(std::string const & type) = 0;
			virtual void print() = 0;
};

#endif