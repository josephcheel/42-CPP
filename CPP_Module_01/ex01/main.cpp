#include "Zombie.hpp"

int main(void)
{
	Zombie *Horde;

	Horde = zombieHorde(5, "Zomboni"); //allocates 5 zombies with the seconda param as name
	int i = 0;
	while (i < 5)
	{
		Horde[i].announce();
		i++;
	}
	return 0;
}