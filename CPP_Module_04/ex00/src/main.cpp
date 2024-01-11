#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main() 
{
	std::cout << std::endl;
	std::cout << std::endl << "-----------Animal-------------" << std::endl << std::endl;
	// Declaration Animal Dog and Cat classed
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	// Get type member function for three classes
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	std::cout << std::endl;

	// Make sound member function for three classes
	j->makeSound(); //will output the cat sound! 
	i->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;
   	// delete objects
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "-----------WrongCat-------------" << std::endl << std::endl;

	// Declaration of WrongAnimal and WrongCat
	const WrongAnimal*	meta1 = new WrongAnimal();
	const WrongAnimal*	i1 = new WrongCat();

	std::cout << std::endl;

	std::cout << i1->getType() << std::endl;
	std::cout << meta1->getType() << std::endl;

	std::cout << std::endl;	

	i1->makeSound(); //will output the WrongAnimal sound!
	meta1->makeSound();

	std::cout << std::endl;

	delete i1;
	delete meta1;
	
	return 0;
}
