#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Default Zombie constructor called" << std::endl;
}
Zombie::~Zombie(void)
{
	std::cout << "Zombie named \"" <<  this->name << "\" destructor called" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
