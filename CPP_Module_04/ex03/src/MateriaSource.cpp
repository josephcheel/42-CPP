#include "../inc/MateriaSource.hpp"	

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}


MateriaSource::MateriaSource(std::string name) 
{
	for(int i = 0; i < 4; i++)
	{
		if (!materias[i].getType().empty())
		{
			materias[i]. = (name);
		}
	}
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource &copy) : materias(copy.materias)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource &copy)
{
	if (this != &copy)
	{
		materias = copy.materias;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{

}