#include "../inc/Character.hpp"

Character::Character() : _name("")
{
	_nbrMateria	= 0;
	for (int i = 0; i < 4; i++)
		this->materias[i] = nullptr;
	std::cout << "Character Default constructor called" << std::endl;
}

Character::Character(const std::string name) : _name(name)
{
	_nbrMateria	= 0;
	for (int i = 0; i < 4; i++)
		this->materias[i] = nullptr;
	std::cout << "Character constructor called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < _nbrMateria; i++)
	{
		if (this->materias[i])
			delete (this->materias[i]);
	}
	std::cout << "Character destructor called" << std::endl;
}
		
Character::Character(Character &copy)
{
	*this = copy;
	std::cout << "Character copy constuctor called" << std::endl;
}

Character &Character::operator=(Character &copy)
{
	std::cout << "Character copy assignment constuctor called" << std::endl;
	if (this != &copy)
	{
		this->_nbrMateria = copy._nbrMateria;
		this->_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->materias[i])
			{
				delete (this->materias[i]);
				this->materias[i] = nullptr;
			}
		}
		for (int i = 0; i < _nbrMateria; i++)
		{
				this->materias[i] = copy.materias[i]->clone();
				// this->materias[i] = nullptr;
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	
	if (_nbrMateria < 4 && m)
	{
		this->materias[_nbrMateria] = m;
		_nbrMateria++;
	}
	else if (_nbrMateria == 4)
		std::cout << "Character already has 4 materia" << std::endl;
}
void Character::unequip(int idx)
{
	if (idx <= _nbrMateria && idx >= 0 && idx < 4)
	{
		this->materias[idx] = nullptr;
	}
	else
		std::cout << "No materia in this slot" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx && idx < 4 && !(this->materias)[idx])
	{
		(this->materias)[idx]->use(target);
	}
	else
		std::cout << "No materia in this slot" << std::endl;
}

void Character::printMaterias()
{
	std::cout << "Character " << _name << " has " << _nbrMateria << " materia(s)" << std::endl;
	for (int i = 0; i < _nbrMateria; i++)
	{
		std::cout << "Materia " << i << " is of type " << this->materias[i]->getType() << std::endl;
	}
}