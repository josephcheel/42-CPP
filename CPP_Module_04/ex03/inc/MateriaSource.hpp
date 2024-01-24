#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource{

	protected:
		AMateria *materias[4];
		int _nbrMateria;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &copy);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		void print();
};

#endif