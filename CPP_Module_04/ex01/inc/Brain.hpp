#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <array>
class Brain {
	
	public:
		Brain();
		~Brain();

		Brain(Brain const &copy);
		
		Brain &operator=(Brain const &copy); 
	protected:
		std::array<std::string, 100> ideas;
};

#endif
