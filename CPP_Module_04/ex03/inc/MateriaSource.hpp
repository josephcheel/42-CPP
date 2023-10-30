#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource{

	protected:
		std::array<AMateria, 4> materias;
	public:
		MateriaSource();
		MateriaSource(MateriaSource &copy);
		~MateriaSource();

		MateriaSource &operator=(MateriaSource &copy);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif