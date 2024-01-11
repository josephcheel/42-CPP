#include "../inc/MateriaSource.hpp"	

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (materias[i])
			delete materias[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materias[i])
			delete materias[i];
	}
	 for (int i = 0; i < 4; ++i)
        materias[i] = copy.materias[i]->clone();
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (materias[i])
			{
				delete materias[i];
				materias[i] = nullptr;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			if (copy.materias[i])
				materias[i] = copy.materias[i]->clone(); 
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!materias[i])
		{
			materias[i] = materia;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materias[i] && materias[i]->getType() == type)
			return (materias[i]->clone());
	}
	return (0);
}