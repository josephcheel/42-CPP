#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {

protected:
	std::string	type;
public:
	Animal();
	Animal(std::string	type);
	virtual ~Animal();
	
	Animal(Animal const &copy);
	Animal const &operator=(Animal const &copy);
	
	std::string		getType() const;
	virtual void	makeSound(void) const;
};

#endif