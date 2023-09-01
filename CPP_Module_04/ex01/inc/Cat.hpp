#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat: public Animal {

public:
	Cat();
	~Cat();

	Cat(Cat const &copy);
	Cat &operator=(Cat const &copy);
	
	void	makeSound(void) const;
};

#endif