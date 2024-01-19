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
		std::string ideas[100];
};

#endif
