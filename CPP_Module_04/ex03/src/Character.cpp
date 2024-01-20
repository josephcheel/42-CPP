#include "../inc/Character.hpp"

Character::Character() : _name("")
{
	for (int i = 0; i < 4; i++)
		this->materias[i] = nullptr;
	std::cout << "Character Default constructor called" << std::endl;
}

Character::Character(const std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->materias[i] = nullptr;
	std::cout << "Character constructor called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
			delete (this->materias[i]);
	}
	std::cout << "Character destructor called" << std::endl;
}
		
Character::Character(Character &copy) : _name(copy._name)
{
	std::cout << "Character copy constuctor called" << std::endl;
}

Character &Character::operator=(Character &copy)
{
	std::cout << "Character copy assignment constuctor called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->materias[i])
				delete (this->materias[i]);
			this->materias[i] = copy.materias[i]->clone();
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
	for(int i = 0; i < 4; i++)
	{
		if (!materias[i])
		{
			materias[i] = m;
			break ;
		}
	}
}
void Character::unequip(int idx)
{
	if (materias[idx]->getType().empty())
	{
		// materias[idx] = nullptr;
	}
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