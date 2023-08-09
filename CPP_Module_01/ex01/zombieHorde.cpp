#include "Zombie.hpp"

Zombie*		zombieHorde(int N, std::string name)
{
	Zombie *Horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		Horde[i].setname(name);
	return (Horde);
}