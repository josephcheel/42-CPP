#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

# define DEBUG		1 
# define INFO		2
# define WARNING	3 
# define ERROR		4

class Harl {
	private:
			void debug( void );
			void info( void );
			void warning( void );
			void error( void );
	public:
			Harl();
			~Harl();
			void complain(std::string level);
			void filtered_complain(std::string level);
};
#endif