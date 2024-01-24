#include "../inc/MateriaSource.hpp"	

MateriaSource::MateriaSource()
{
	_nbrMateria = 0;
	for (int i = 0; i < 4; ++i)
	{
		materias[i] = nullptr;
	}
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

MateriaSource::MateriaSource(const MateriaSource &copy) : _nbrMateria(copy._nbrMateria)
{
	 for (int i = 0; i < 4; ++i)
        materias[i] = copy.materias[i]->clone();
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	_nbrMateria = copy._nbrMateria;
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
			else
				materias[i] = nullptr;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (_nbrMateria < 4)
	{
		materias[_nbrMateria] = materia;
		_nbrMateria++;
	}
	else
		std::cout << "MateriaSource is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{

	for (int i = 0; i < _nbrMateria; ++i)
	{
		if (materias[i] && materias[i]->getType() == type)
			return (materias[i]->clone());
	}
	return (0);
}

void	MateriaSource::print()
{
	std::cout << "MateriaSource has " << _nbrMateria << " materia" << std::endl;
	for (int i = 0; i < _nbrMateria ; ++i)
	{
		if (materias[i])
			std::cout << "Materia " << i << " : " << materias[i]->getType() << std::endl;
		else
			std::cout << "Materia " << i << " : NULL" << std::endl;
	}
}