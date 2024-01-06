#include "../inc/Character.hpp"

Character::Character() : _name("")
{
	std::cout << "Character Default constructor called" << std::endl;
}

Character::Character(const std::string name) : _name(name)
{
	std::cout << "Character constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
}
		
Character::Character(Character &copy) : _name(copy._name)
{
	std::cout << "Character copy constuctor called" << std::endl;
}

Character &Character::operator=(Character &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		//this->materias = copy->materias;
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
		if (materias[i]->getType().empty())
			materias[i] = m;
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
	if (materias[idx]->getType().empty())
	{
		(void)target;
	}
}