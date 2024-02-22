#ifndef SCALAVAR_CONVERTER_HPP
# define SCALAVAR_CONVERTER_HPP

# include <iostream>
# include <limits>
# include <sstream>
# include <stdint.h>

# include "Data.hpp"

class Data;

class Serializer
{
	public:	
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer(void);
		Serializer(Serializer const & src);
		Serializer(std::string str);

		~Serializer(void);
		Serializer &operator=(Serializer const & copy);
};

#endif