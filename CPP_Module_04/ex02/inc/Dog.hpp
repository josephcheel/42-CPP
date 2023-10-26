#ifndef DOG_HPP
# define DOG_HPP

# include "AbstractAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog: public AbstractAnimal {

protected:
	std::string	type;
public:
	Dog();
	~Dog();

	Dog(Dog const &copy);
	Dog &operator=(Dog const &copy);
	
	void	makeSound(void) const;
private:
	Brain *DogBrain;
};

#endif
