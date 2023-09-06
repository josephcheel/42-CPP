#include "../inc/Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie HeapZombie = Zombie(name);
	HeapZombie.announce();
	return ;
}
