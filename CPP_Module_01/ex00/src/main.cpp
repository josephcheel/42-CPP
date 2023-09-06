#include "../inc/Zombie.hpp"

int main(void) 
{
	//Zombie created in the Stack
	randomChump("ZombieStack");
	
	//Zombie created in the Heap
	Zombie *Zombie_Heap = newZombie("ZombieHeap");
	Zombie_Heap->announce();

	// Heap must be deleted, Stack is automatically descontrusted in the return
	delete Zombie_Heap;
	return 0;
}
