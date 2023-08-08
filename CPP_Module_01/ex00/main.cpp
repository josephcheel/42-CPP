#include "Zombie.hpp"

int main(void) 
{
	//Zombie created in the Stack
	randomChump("Joseph");
	
	//Zombie created in the Heap
	Zombie *Zombie_Heap = newZombie("Pau");
	Zombie_Heap->announce();

	// Heap must be deleted, Stack is automatically descontrusted in the return
	delete Zombie_Heap;
	return 0;
}