#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main() 
{

	const Animal* j = new Dog(); 
	const Animal* i = new Cat();

	delete j;//should not create a leak 
	delete i;
	
	const Animal* Array[20];

	for(int i = 0; i < 10; i++) {
		Array[i] = new Dog();
	}
	for(int i= 10; i< 20; i++) {
		Array[i] = new Cat();
	}
	for (int i = 0; i < 20; i++) {
   		delete Array[i];
	}
	
	return 0;
}
