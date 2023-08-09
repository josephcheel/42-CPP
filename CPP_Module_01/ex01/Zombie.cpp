#include "Zombie.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::Zombie(std::string name) : name(name)
{
	return ;
}
Zombie::~Zombie(void)
{
	std::cout << this->name << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setname(std::string name)
{
	this->name = name;
}

