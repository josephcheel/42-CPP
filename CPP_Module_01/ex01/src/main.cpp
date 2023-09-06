#include "../inc/Zombie.hpp"

int main(void)
{
	Zombie *Horde;
	
	//allocates 5 zombies with the seconda param as name
	Horde = zombieHorde(5, "Hoooooordeeee"); 
	
	//prints the names 
	int i = 0;
	while (i < 5)
	{
		Horde[i].announce();
		i++;
	}
	delete[] Horde;
	return 0;
}