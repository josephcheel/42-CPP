#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
// #include "../inc/WrongAnimal.hpp"
// #include "../inc/WrongCat.hpp"

int main() 
{
	std::cout << "--------------SUBJECT TEST I---------------" << std::endl << std::endl;
	{
			
		const Animal* j = new Dog();
		std::cout << "\n";
		const Animal* i = new Cat();
		std::cout << "\n";
		delete j;//should not create a leak
		std::cout << "\n";
		delete i;

		std::cout << std::endl << "--------------DOG CONSTRUCTOR---------------" << std::endl << std::endl;
		const Animal* Array[20];
		for(int i = 0; i < 10; i++) {
			Array[i] = new Dog();
			std::cout << "\n";
		}
		std::cout << std::endl << "--------------CAT CONSTRUCTOR---------------" << std::endl << std::endl;
		for(int i= 10; i < 20; i++) {
			Array[i] = new Cat();
			std::cout << "\n";
		}
		std::cout << std::endl << "--------------DOG AND CAT DESTRUCTOR---------------" << std::endl << std::endl;
		for (int i = 0; i < 20; i++) {
			delete Array[i];
			std::cout << "\n";
			
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
}
