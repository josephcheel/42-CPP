#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal {

public:
	WrongCat( void );
	~WrongCat( void );

	WrongCat( std::string type );
	WrongCat( WrongCat const &copy );
	
	WrongCat	&operator=( WrongCat const &copy );

	void		makeSound(void) const;
};

#endif