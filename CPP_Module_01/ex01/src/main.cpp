#include "../inc/Zombie.hpp"

int main(void)
{
	Zombie *Horde;
	int N = 5; //nbr of the horde

	//allocates 5 zombies with the seconda param as name
	Horde = zombieHorde(N, "Hoooooordeeee"); 
	
	//prints the names 
	int i = 0;
	while (i < N)
	{
		Horde[i].announce();
		i++;
	}
	delete[] Horde;
	return 0;
}