#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main() 
{
	{
		std::cout << std::endl;
		std::cout << std::endl << "-----------Animal Subject-------------" << std::endl << std::endl;
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
	}
	std::cout << std::endl << "-----------Animal-------------" << std::endl << std::endl;
	{
		// Default constructor
		Animal animal;

		// Copy constructor
		Animal animal1(Animal("rare"));
		
		// Copy Assignment
		animal = animal1;


		std::cout << animal.getType() << std::endl;
		animal.makeSound();

		std::cout << animal1.getType() << std::endl;
		animal1.makeSound();
	}
	std::cout << std::endl << "-----------Cat-------------" << std::endl << std::endl;
	{
		// Default constructor
		Cat cat;

		// Copy constructor
		Cat cat1((Cat()));
		
		// Copy Assignment
		cat = cat1;

		std::cout << cat.getType() << std::endl;
		cat.makeSound();

		std::cout << cat1.getType() << std::endl;
		cat1.makeSound();
	}
	std::cout << std::endl << "-----------Dog-------------" << std::endl << std::endl;
	{
		// Default constructor
		Dog dog;

		// Copy constructor
		Dog dog1((Dog()));
		
		// Copy Assignment
		dog = dog1;

		std::cout << dog.getType() << std::endl;
		dog.makeSound();

		std::cout << dog1.getType() << std::endl;
		dog1.makeSound();
	}
	std::cout << std::endl << "-----------WrongCat-------------" << std::endl << std::endl;
	{
		//Default Constructor
		WrongAnimal wrongAnimal;
		WrongCat wrongCat;

		// Copy Constructor
		WrongAnimal wrongAnimal1(wrongAnimal);
		WrongCat wrongCat1(wrongCat);

		// Copy Assignment
		wrongAnimal = wrongAnimal1;
		wrongCat = wrongCat1;
	}
	{
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
	}
}
