#ifndef ABSTRACT_ANIMAL_HPP
# define ABSTRACT_ANIMAL_HPP

# include <iostream>

class AbstractAnimal {

protected:
	std::string	type;
public:
	AbstractAnimal();
	AbstractAnimal(std::string _type);
	virtual ~AbstractAnimal() = 0;
	
	AbstractAnimal(AbstractAnimal const &copy);
	AbstractAnimal const &operator=(AbstractAnimal const &copy);
	
	std::string		getType() const;
	virtual void	makeSound(void) const = 0;
};

#endif