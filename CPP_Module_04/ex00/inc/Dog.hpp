#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog: public Animal {

protected:
	std::string	type;
public:
	Dog();
	~Dog();

	Dog(Dog const &copy);
	Dog &operator=(Dog const &copy);
	
	void	makeSound(void) const;
};

#endif