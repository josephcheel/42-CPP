#ifndef CAT_HPP
# define CAT_HPP

# include "AbstractAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat: public AbstractAnimal {

public:
	Cat();
	~Cat();

	Cat(Cat const &copy);
	Cat &operator=(Cat const &copy);
	
	void	makeSound(void) const;
private:
	Brain *CatBrain;
};

#endif
