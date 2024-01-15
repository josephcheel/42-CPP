#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
// #include "../inc/WrongAnimal.hpp"
// #include "../inc/WrongCat.hpp"

int main() 
{
	std::cout << "--------------SUBJECT TEST---------------" << std::endl << std::endl;
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

	}
	std::cout << "--------------DEEP COPY---------------" << std::endl << std::endl;
	{
					
		Dog basic;
		{
			std::cout << std::endl;
			Dog tmp = basic;
			std::cout << std::endl;
		}
	}
	std::cout << "--------------BRAIN---------------" << std::endl << std::endl;
	{
		// Default Constructor
		Brain test();

		// Copy constructor
		Brain test2(Brain());

		// Copy Assignment
		Brain copy() = new Brain();
		

	}
}
