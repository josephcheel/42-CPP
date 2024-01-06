#include "../inc/MateriaSource.hpp"	

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	 for (int i = 0; i < 4; ++i)
        materias[i] = copy.materias[i]->clone();
	//materias(copy.materias
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete materias[i];
			materias[i] = nullptr;
		}
		for (int i = 0; i < 4; ++i)
		{
			materias[i] = copy.materias[i]->clone(); 
		}
		//materias = copy.materias;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria *materia = new AMateria(type);
	return (materia);
}