#include "../inc/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Default Zombie constructor called" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Default Zombie name constructor called" << std::endl;
}
Zombie::~Zombie(void)
{
	std::cout << "Zombie destructor called" << std::endl;
}

void	Zombie::setname(std::string name)
{
	std::cout << "Set name function called" << std::endl;
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

