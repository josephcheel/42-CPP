#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/AbstractAnimal.hpp"

int main() 
{

	const AbstractAnimal* j = new Dog(); 
	const AbstractAnimal* i = new Cat();


	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	
	j->makeSound();
	i->makeSound();
	
	delete j;//should not create a leak 
	delete i;
	
}
